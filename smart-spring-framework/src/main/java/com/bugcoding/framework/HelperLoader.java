package com.bugcoding.framework;

import com.bugcoding.framework.helper.*;
import com.bugcoding.framework.util.ClassUtil;

/**
 * 加载Helper相关类
 */
public final class HelperLoader {

    public static void init() {
        Class<?>[] classList = {
                ClassHelper.class,
                BeanHelper.class,
                AopHelper.class,
                IocHelper.class,
                ControllerHelper.class
        };
        for (Class<?> cls : classList) {
            ClassUtil.loadClass(cls.getName());
        }
    }
}
