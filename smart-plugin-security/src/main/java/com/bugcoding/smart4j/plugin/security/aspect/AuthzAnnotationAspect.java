package com.bugcoding.smart4j.plugin.security.aspect;

import com.bugcoding.framework.annotation.Aspect;
import com.bugcoding.framework.annotation.Controller;
import com.bugcoding.framework.proxy.AspectProxy;
import com.bugcoding.smart4j.plugin.security.annotation.User;
import com.bugcoding.smart4j.plugin.security.exception.AuthzException;
import org.apache.shiro.SecurityUtils;
import org.apache.shiro.subject.PrincipalCollection;
import org.apache.shiro.subject.Subject;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;

/**
 * 授权注解切面
 */
@Aspect(Controller.class)
public class AuthzAnnotationAspect extends AspectProxy {

    private static final Class[] ANNOTATION_CLASS_ARRAY = {
            User.class
    };

    @Override
    public void before(Class<?> cls, Method method, Object[] params) throws Throwable {
        // 从目标类与目标方法中获取对应的注解
        Annotation annotation = getAnnotation(cls, method);
        if (annotation != null) {
            // 判断授权注解的类型
            Class<?> annotationType = annotation.annotationType();
            if (annotationType.equals(annotationType)) {
                handleUser();
            }
        }
    }

    private Annotation getAnnotation(Class<?> cls, Method method) {
        // 遍历所有的授权注解
        for (Class<? extends Annotation> annotationClass : ANNOTATION_CLASS_ARRAY) {
            // 首先判断目标方法是否带有授权注解
            if (method.isAnnotationPresent(annotationClass)) {
                return method.getAnnotation(annotationClass);
            }

            // 然后判断目标类是否带有授权注解
            if (cls.isAnnotationPresent(annotationClass)) {
                return cls.getAnnotation(annotationClass);
            }

        }
        // 若目标方法与目标类均为带有授权注解, 则返回空对象
        return null;
    }

    private void handleUser() {
        Subject currentUser = SecurityUtils.getSubject();
        PrincipalCollection principalCollection = currentUser.getPrincipals();
        if (principalCollection == null || principalCollection.isEmpty()) {
            throw new AuthzException("当前用户尚未登录");
        }
    }
}
