package com.bugcoding.smart4j.plugin.security;

import org.apache.shiro.cache.CacheManager;
import org.apache.shiro.cache.MemoryConstrainedCacheManager;
import org.apache.shiro.mgt.CachingSecurityManager;
import org.apache.shiro.mgt.RealmSecurityManager;
import org.apache.shiro.realm.Realm;
import org.apache.shiro.web.mgt.WebSecurityManager;
import org.apache.shiro.web.servlet.ShiroFilter;
import com.bugcoding.smart4j.plugin.security.realm.SmartCustomRealm;
import com.bugcoding.smart4j.plugin.security.realm.SmartJdbcRealm;

import java.util.LinkedHashSet;
import java.util.Set;

/**
 * ��ȫ������
 */
public class SmartSecurityFilter extends ShiroFilter {

    @Override
    public void init() throws Exception {
        super.init();
        WebSecurityManager webSecurityManager = super.getSecurityManager();
        // ����Realm, ��ͬʱ֧�ֶ��Realm, �������Ⱥ�˳���ö��ŷָ�
        setRealms(webSecurityManager);
        setCache(webSecurityManager);
    }

    private void setRealms(WebSecurityManager webSecurityManager) {
        // ��ȡsmart.plugin.security.realms������
        String securityRealms = SecurityConfig.getRealms();
        if (securityRealms != null) {
            // ���ݶ��Ž��в��
            String[] securityRealmArray = securityRealms.split(",");
            if (securityRealmArray.length > 0) {
                // ʹ Realm�߱�Ψһ�Ժ�˳����
                Set<Realm> realms = new LinkedHashSet<Realm>();
                for (String securityRealm : securityRealmArray) {
                    if (securityRealm.equalsIgnoreCase(SecurityConstant.REALMS_JDBC)) {
                        // ��ӻ���JDBC��Realm, ���������SQL��ѯ���
                        addJdbcRealm(realms);
                    } else if (securityRealm.equalsIgnoreCase(SecurityConstant.REALMS_CUSTOM)) {
                        addCustomRealm(realms);
                    }
                }
                RealmSecurityManager realmSecurityManager = (RealmSecurityManager) webSecurityManager;
                realmSecurityManager.setRealms(realms); // ����Realm
            }
        }
    }

    private void addJdbcRealm(Set<Realm> realms) {
        // ����Լ�ʵ�ֵĻ���JDBC��Ream
        SmartJdbcRealm smartJdbcRealm = new SmartJdbcRealm();
        realms.add(smartJdbcRealm);
    }

    private void addCustomRealm(Set<Realm> realms) {
        // ��ȡsmart.plugin.security.custom.class������
        SmartSecurity smartSecurity = SecurityConfig.getSmartSecurity();
        // ����Լ�ʵ�ֵ�Realm
        SmartCustomRealm smartSecurityRealm = new SmartCustomRealm(smartSecurity);
        realms.add(smartSecurityRealm);
    }

    private void setCache(WebSecurityManager webSecurityManager) {
        // ��ȡsmart.plugin.security.cache������
        if (SecurityConfig.isCacheable()) {
            CachingSecurityManager cachingSecurityManager = (CachingSecurityManager) webSecurityManager;
            // ʹ�û����ڴ��CacheManager
            CacheManager cacheManager = new MemoryConstrainedCacheManager();
            cachingSecurityManager.setCacheManager(cacheManager);
        }
    }

}
