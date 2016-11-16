package plugin.security;

import org.apache.shiro.web.env.EnvironmentLoaderListener;

import javax.servlet.FilterRegistration;
import javax.servlet.ServletContainerInitializer;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import java.util.Set;

/**
 * Smart  Security���
 */
public class SmartSecurityPlugin implements ServletContainerInitializer {

    public void onStartup(Set<Class<?>> handleTypes, ServletContext servletContext) throws ServletException {
        // ���ó�ʼ������
        servletContext.setInitParameter("shiroConfigLocations", "classpath:smart-security.ini");
        // ע��Listener
        servletContext.addListener(EnvironmentLoaderListener.class);
        // ע��Filter
        FilterRegistration.Dynamic smartSecurityFilter = servletContext.addFilter("SmartSecurityFilter", SmartSecurityFilter.class);
        smartSecurityFilter.addMappingForUrlPatterns(null, false, "/*");
    }
}
