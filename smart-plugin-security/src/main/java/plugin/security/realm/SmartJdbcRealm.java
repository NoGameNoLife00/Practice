package plugin.security.realm;


import com.bugcoding.framework.helper.DatabaseHelper;
import org.apache.shiro.realm.jdbc.JdbcRealm;
import plugin.security.SecurityConfig;
import plugin.security.password.Md5CredentialsMatcher;

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
