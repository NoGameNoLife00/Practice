package com.bugcoding.framework.bean;

import java.lang.reflect.Method;

/**
 * 请求信息
 */
public class Handler {

    private Class<?> controllerClass;

    private Method actionMethod;

    public Handler(Class<?> controllerClass, Method actionMethod) {
        this.controllerClass = controllerClass;
        this.actionMethod = actionMethod;
    }

    public Class<?> getControllerClass() {
        return  controllerClass;
    }

    public Method getActionMethod() {
        return actionMethod;
    }

}
