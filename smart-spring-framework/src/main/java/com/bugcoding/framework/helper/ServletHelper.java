package com.bugcoding.framework.helper;

import org.omg.CORBA.Object;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Servlet ������
 */
public final class ServletHelper {
    private static final Logger LOGGER = LoggerFactory.getLogger(ServletHelper.class);

    /**
     * ÿ���̶߳���ӵ��һ��ServletHelperʵ��
     */
    private static final ThreadLocal<ServletHelper> SERVLET_HELPER_HOLDER = new ThreadLocal<ServletHelper>();

    private HttpServletRequest request;
    private HttpServletResponse response;

    private ServletHelper(HttpServletRequest request, HttpServletResponse response) {
        this.request = request;
        this.response = response;
    }

    /**
     * ��ʼ��
     * @param request
     * @param response
     */
    public static void init(HttpServletRequest request, HttpServletResponse response) {
        SERVLET_HELPER_HOLDER.set(new ServletHelper(request, response));
    }

    /**
     * ����
     */
    public static void destroy() {
        SERVLET_HELPER_HOLDER.remove();
    }

    /**
     * ��ȡRequest����
     * @return
     */
    private static HttpServletRequest getRequest() {
        return SERVLET_HELPER_HOLDER.get().request;
    }

    /**
     * ��ȡResponse����
     * @return
     */
    private static HttpServletResponse getResponse() {
        return SERVLET_HELPER_HOLDER.get().response;
    }

    /**
     *  ��ȡSession����
     * @return
     */
    private static HttpSession getSession() {
        return getRequest().getSession();
    }

    /**
     * ��ȡServletContext����
     * @return
     */
    private static ServletContext getServletContext() {
        return getRequest().getServletContext();
    }

    /**
     * �����Է���Request��
     * @param key
     * @param value
     */
    public static void setRequestAttribute(String key, Object value) {
        getRequest().setAttribute(key, value);
    }

    /**
     * ��Request�л�ȡ����
     * @param key
     * @param <T>
     * @return
     */
    @SuppressWarnings("unchecked")
    public static <T> T getRequestAttribute(String key) {
        return (T) getRequest().getAttribute(key);
    }

    /**
     * ��Request���Ƴ�����
     * @param key
     */
    public static void removeRequestAttribute(String key) {
        getRequest().removeAttribute(key);
    }

    /**
     * �����ض�����Ӧ
     * @param location
     */
    public static void sendRedirect(String location) {
        try {
            getResponse().sendRedirect(getRequest().getContextPath() + location);
        } catch (IOException e) {
            LOGGER.error("redirect failure", e);
        }
    }

    /**
     * �����Է���Session
     * @param key
     * @param value
     */
    public static void setSessionAttribute(String key, Object value) {
        getSession().setAttribute(key, value);
    }

    /**
     * ��Session�л�ȡ����
     * @param key
     * @param <T>
     * @return
     */
    public static <T> T getSessionAttribute(String key) {
        return (T) getRequest().getSession().getAttribute(key);
    }

    /**
     * ��Session���Ƴ�����
     * @param key
     */
    public static void removeSessionAttribute(String key) {
        getRequest().getSession().removeAttribute(key);
    }

    /**
     * ʹSessionʧЧ
     */
    public static  void invalidateSession() {
        getRequest().getSession().invalidate();
    }
}
