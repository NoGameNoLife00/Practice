package com.bugcoding.smart4j.plugin.security.realm;


import com.bugcoding.framework.helper.DatabaseHelper;
import org.apache.shiro.realm.jdbc.JdbcRealm;
import com.bugcoding.smart4j.plugin.security.SecurityConfig;
import com.bugcoding.smart4j.plugin.security.password.Md5CredentialsMatcher;

/**
 * »ùÓÚJdbcµÄRealm
 */
public class SmartJdbcRealm extends JdbcRealm {

    public SmartJdbcRealm() {
        super.setDataSource(DatabaseHelper.getDataSource());
        super.setAuthenticationQuery(SecurityConfig.getJdbcAuthcQuery());
        super.setUserRolesQuery(SecurityConfig.getJdbcRolesQuery());
        super.setPermissionsQuery(SecurityConfig.getJdbcPermissionsQuery());
        super.setCredentialsMatcher(new Md5CredentialsMatcher());
    }
}
