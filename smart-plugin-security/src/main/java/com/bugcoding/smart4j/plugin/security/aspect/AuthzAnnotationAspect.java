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
 * ��Ȩע������
 */
@Aspect(Controller.class)
public class AuthzAnnotationAspect extends AspectProxy {

    private static final Class[] ANNOTATION_CLASS_ARRAY = {
            User.class
    };

    @Override
    public void before(Class<?> cls, Method method, Object[] params) throws Throwable {
        // ��Ŀ������Ŀ�귽���л�ȡ��Ӧ��ע��
        Annotation annotation = getAnnotation(cls, method);
        if (annotation != null) {
            // �ж���Ȩע�������
            Class<?> annotationType = annotation.annotationType();
            if (annotationType.equals(annotationType)) {
                handleUser();
            }
        }
    }

    private Annotation getAnnotation(Class<?> cls, Method method) {
        // �������е���Ȩע��
        for (Class<? extends Annotation> annotationClass : ANNOTATION_CLASS_ARRAY) {
            // �����ж�Ŀ�귽���Ƿ������Ȩע��
            if (method.isAnnotationPresent(annotationClass)) {
                return method.getAnnotation(annotationClass);
            }

            // Ȼ���ж�Ŀ�����Ƿ������Ȩע��
            if (cls.isAnnotationPresent(annotationClass)) {
                return cls.getAnnotation(annotationClass);
            }

        }
        // ��Ŀ�귽����Ŀ�����Ϊ������Ȩע��, �򷵻ؿն���
        return null;
    }

    private void handleUser() {
        Subject currentUser = SecurityUtils.getSubject();
        PrincipalCollection principalCollection = currentUser.getPrincipals();
        if (principalCollection == null || principalCollection.isEmpty()) {
            throw new AuthzException("��ǰ�û���δ��¼");
        }
    }
}
