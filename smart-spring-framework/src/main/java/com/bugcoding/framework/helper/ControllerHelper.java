package com.bugcoding.framework.helper;

import com.bugcoding.framework.annotation.Action;
import com.bugcoding.framework.bean.Handler;
import com.bugcoding.framework.bean.Request;
import com.bugcoding.framework.util.ArrayUtil;
import com.bugcoding.framework.util.CollectionUtil;

import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * 控制器助手类
 */
public final class ControllerHelper {
    /*
    请求与处理方法的映射关系
     */
    private static final Map<Request, Handler> ACTION_MAP = new HashMap<Request, Handler>();

    static {
        // 获取所有Controller类
        Set<Class<?>> controllerClassSet = ClassHelper.getControllerClassSet();
        if (CollectionUtil.isNotEmpty(controllerClassSet)) {
            // 遍历Controller类
            for (Class<?> controllerClass : controllerClassSet) {
                // 获取Controller类中定义的方法
                Method[] methods = controllerClass.getMethods();
                if (ArrayUtil.isNotEmpty(methods)) {
                    // 遍历Controller类中的方法
                    for (Method method : methods) {
                        // 获取有Action注解的方法
                        if (method.isAnnotationPresent(Action.class)) {
                            Action action = method.getAnnotation(Action.class);
                            String mapping = action.value();
                            // 验证URL映射规则
                            if (mapping.matches("\\w+:/\\w*")) {
                                String [] array = mapping.split(":");
                                if (ArrayUtil.isNotEmpty(array) &&
                                        array.length == 2) {
                                    // 获取请求方法与路径
                                    String requestMethod = array[0];
                                    String requestPath = array[1];
                                    Request request = new Request(requestMethod, requestPath);
                                    Handler handler = new Handler(controllerClass, method);
                                    ACTION_MAP.put(request, handler);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    public static Handler getHandler(String requestMethod, String requestPath) {
        Request request = new Request(requestMethod, requestPath);
        return ACTION_MAP.get(request);
    }
}
