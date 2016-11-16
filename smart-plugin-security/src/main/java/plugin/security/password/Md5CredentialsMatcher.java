package plugin.security.password;

import com.bugcoding.framework.util.CodecUtil;
import org.apache.shiro.authc.AuthenticationInfo;
import org.apache.shiro.authc.AuthenticationToken;
import org.apache.shiro.authc.UsernamePasswordToken;
import org.apache.shiro.authc.credential.CredentialsMatcher;

/**
 * Md5 ����ƥ����
 */
public class Md5CredentialsMatcher implements CredentialsMatcher {

    public boolean doCredentialsMatch(AuthenticationToken authenticationToken, AuthenticationInfo authenticationInfo) {
        // ��ȡ�ӱ��ύ�����롢���ġ���δͨ��MD5����
        String submitted = String.valueOf(((UsernamePasswordToken) authenticationToken).getPassword());
        // ��ȡ���ݿ��д洢�����룬��ͨ��MD5����
        String encryptyed = String.valueOf(authenticationInfo.getCredentials());
        return CodecUtil.md5(submitted).equals(encryptyed);
    }
}
