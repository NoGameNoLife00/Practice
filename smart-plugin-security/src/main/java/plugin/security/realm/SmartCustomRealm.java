package plugin.security.realm;

import org.apache.shiro.authc.*;
import org.apache.shiro.authz.AuthorizationInfo;
import org.apache.shiro.authz.SimpleAuthorizationInfo;
import org.apache.shiro.realm.AuthorizingRealm;
import org.apache.shiro.subject.PrincipalCollection;
import org.apache.shiro.subject.SimplePrincipalCollection;
import plugin.security.SecurityConstant;
import plugin.security.SmartSecurity;
import plugin.security.password.Md5CredentialsMatcher;

import java.util.HashSet;
import java.util.Set;

/**
 * �Զ���Realm
 */
public class SmartCustomRealm extends AuthorizingRealm {

    private final SmartSecurity smartSecurity;

    public SmartCustomRealm(SmartSecurity smartSecurity) {
        this.smartSecurity = smartSecurity;
        super.setName(SecurityConstant.REALMS_CUSTOM);
        super.setCredentialsMatcher(new Md5CredentialsMatcher());
    }

    @Override
    protected AuthorizationInfo doGetAuthorizationInfo(PrincipalCollection principalCollection) {
        if (principalCollection == null) {
            throw  new AuthenticationException("parameter principals is null");
        }
        // ��ȡ����֤�û��û���
        String username = (String) super.getAvailablePrincipal(principalCollection);

        // ͨ��SmartSecurity�ӿڲ������û�����ȡ��ɫ����
        Set<String> roleNameSet = smartSecurity.getRoleNameSet(username);

        // ͨ��SmartSecurity�ӿڲ����ݽ�ɫ����ȡ��Ӧ��Ȩ��������
        Set<String> permissionNameSet = new HashSet<String>();
        if (roleNameSet != null && roleNameSet.size() > 0) {
            for (String roleName : roleNameSet) {
                Set<String> currentPermissionNameSet = smartSecurity.getPermissionNameSet(roleName);
                permissionNameSet.addAll(currentPermissionNameSet);
            }
        }

        // ����ɫ��������Ȩ�޼��Ϸ���AuthorizationInfo������,�Ա��������Ȩ����
        SimpleAuthorizationInfo authorizationInfo = new SimpleAuthorizationInfo();
        authorizationInfo.setRoles(roleNameSet);
        authorizationInfo.setStringPermissions(permissionNameSet);
        return authorizationInfo;
    }

    @Override
    protected AuthenticationInfo doGetAuthenticationInfo(AuthenticationToken authenticationToken) throws AuthenticationException {
        if (authenticationToken == null) {
            throw new AuthenticationException("parameter token is null");
        }

        // ͨ��AuthenicationToken�����ȡ�ӱ��ύ�������û���
        String username = ((UsernamePasswordToken)authenticationToken).getUsername();
        // ͨ��SmartSecurity�ӿڲ������û�����ȡ���ݿ��д�ŵ�����
        String password = smartSecurity.getPassword(username);

        // ���û������������AuthenticationInfo�����У������������֤����
        SimpleAuthenticationInfo authenticationInfo = new SimpleAuthenticationInfo();
        authenticationInfo.setPrincipals(new SimplePrincipalCollection(username, super.getName()));
        authenticationInfo.setCredentials(password);
        return authenticationInfo;
    }
}
