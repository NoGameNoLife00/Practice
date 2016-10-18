package com.bugcoding.framework.helper;

import com.bugcoding.framework.annotation.Inject;
import com.bugcoding.framework.util.ArrayUtil;
import com.bugcoding.framework.util.CollectionUtil;
import com.bugcoding.framework.util.ReflectionUtil;

import java.lang.reflect.Field;
import java.util.Map;

/**
 * 依赖注入助手类
 */
public final class IocHelper {

    static {
        Map<Class<?>, Object> beanMap = BeanHelper.getBeanMap();
        if (CollectionUtil.isNotEmpty(beanMap)) {
            // 遍历Bean map
            for (Map.Entry<Class<?>, Object> beanEntry : beanMap.entrySet()) {
                // 从BeanMap 中获取Bean类与Bean实例
                Class<?> beanClass = beanEntry.getKey();
                Object beanInstance = beanEntry.getValue();
                // 获取Bean类定义的所有成员变量
                Field[] beanFields = beanClass.getDeclaredFields();
                if (ArrayUtil.isNotEmpty(beanFields)) {
                    // 遍历 bean field
                    for (Field beanField : beanFields) {
                        // 判断当前 Bean Field 是否带有Inject 注解
                        if (beanField.isAnnotationPresent(Inject.class)) {
                            // 在Bean Map中获取Bean Field对应的实例
                            Class<?> beanFieldClass = beanField.getType();
                            Object beanFieldInstance = beanMap.get(beanFieldClass);
                            if (beanFieldInstance != null) {
                                ReflectionUtil.setField(beanInstance, beanField, beanFieldInstance);
                            }
                        }
                    }
                }
            }
        }
    }
}
