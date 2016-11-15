package com.bugcoding.framework;

import com.bugcoding.framework.bean.Data;
import com.bugcoding.framework.bean.Handler;
import com.bugcoding.framework.bean.Param;
import com.bugcoding.framework.bean.View;
import com.bugcoding.framework.helper.*;
import com.bugcoding.framework.util.*;

import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletRegistration;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Method;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Map;

/**
 * 请求转发器
 */
@WebServlet(urlPatterns = "/*", loadOnStartup = 0)
public class DispatcherServlet extends HttpServlet{

    @Override
    public void init(ServletConfig config) throws ServletException {
        HelperLoader.init();
        // 获取ServletContext对象
        ServletContext servletContext = config.getServletContext();
        // 注册Jsp的servlet
        ServletRegistration jspServlet = servletContext.getServletRegistration("jsp");
        jspServlet.addMapping(ConfigHelper.getAppJspPath() + "*");
        // 注册处理静态资源的默认Servlet
        ServletRegistration defaultServlet = servletContext.getServletRegistration("default");
        defaultServlet.addMapping(ConfigHelper.getAppAssetPath() + "*");
        UploadHepler.init(servletContext);
        // 初始化相关Helper类
        super.init(config);
    }

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        super.service(req, resp);

        // 获取请求方法与路径
        String requestMethod = req.getMethod().toLowerCase();
        String requestPath = req.getPathInfo();

        if (requestPath.equals("/favicon.ico")) {
            return;
        }

        // 获取Action
        Handler handler = ControllerHelper.getHandler(requestMethod, requestPath);

        if (handler != null) {
            // 获取Controller类及其Bean实例
            Class<?> controllerClass = handler.getControllerClass();
            Object controllerBean = BeanHelper.getBean(controllerClass);

            Param param;
            if (UploadHepler.isMultipart(req)) {
                param = UploadHepler.createParam(req);
            } else {
                param = RequestHelper.createParam(req);
            }

            Object result;
            // 调用Action方法
            Method actionMethod = handler.getActionMethod();

            if (param.isEmpty()){
                result = ReflectionUtil.invokeMethod(controllerBean, actionMethod);
            } else {
                result = ReflectionUtil.invokeMethod(controllerBean, actionMethod, param);
            }

            // 处理Action方法返回值
            if (result instanceof View) {
                // 返回JSP页面
                handleViewResult((View) result, req, resp);
            } else if (result instanceof Data) {
                // 返回Json数据
                handleDataResult((Data) result, resp);
            }

        }
    }

    private void handleViewResult(View view, HttpServletRequest request,
                                  HttpServletResponse response) throws IOException, ServletException {
        String path = view.getPath();
        if (StringUtil.isNotEmpty(path)) {
            if (StringUtil.isNotEmpty(path)) {
                if (path.startsWith("/")) {
                    response.sendRedirect(request.getContextPath() + path);
                } else {
                    Map<String, Object> model = view.getModel();
                    for (Map.Entry<String, Object> entry : model.entrySet()) {
                        request.setAttribute(entry.getKey(), entry.getValue());
                    }
                    request.getRequestDispatcher(ConfigHelper.getAppJspPath() + path).forward(request, response);
                }
            }
        }
    }

    private void handleDataResult(Data data, HttpServletResponse response) throws IOException {
        Object model = data.getModel();
        if (model != null) {
            response.setContentType("application/json");
            response.setCharacterEncoding("UTF-8");
            PrintWriter writer = response.getWriter();
            String json = JsonUtil.toJson(model);
            writer.write(json);
            writer.flush();
            writer.close();
        }
    }
}
