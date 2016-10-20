package com.bugcoding.framework;

import com.bugcoding.framework.helper.BeanHelper;
import com.bugcoding.framework.helper.ClassHelper;
import com.bugcoding.framework.helper.ControllerHelper;
import com.bugcoding.framework.helper.IocHelper;
import com.bugcoding.framework.util.ClassUtil;

/**
 * 加载Helper相关类
 */
public final class HelperLoader {

    public static void init() {
        Class<?>[] classList = {
                ClassHelper.class,
                BeanHelper.class,
                IocHelper.class,
                ControllerHelper.class
        };
        for (Class<?> cls : classList) {
            ClassUtil.loadClass(cls.getName());
        }
    }
}
