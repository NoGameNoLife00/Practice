package plugin.security.password;

import com.bugcoding.framework.util.CodecUtil;
import org.apache.shiro.authc.AuthenticationInfo;
import org.apache.shiro.authc.AuthenticationToken;
import org.apache.shiro.authc.UsernamePasswordToken;
import org.apache.shiro.authc.credential.CredentialsMatcher;

/**
 * Md5 密码匹配器
 */
public class Md5CredentialsMatcher implements CredentialsMatcher {

    public boolean doCredentialsMatch(AuthenticationToken authenticationToken, AuthenticationInfo authenticationInfo) {
        // 获取从表单提交的密码、明文、尚未通过MD5加密
        String submitted = String.valueOf(((UsernamePasswordToken) authenticationToken).getPassword());
        // 获取数据库中存储的密码，已通过MD5加密
        String encryptyed = String.valueOf(authenticationInfo.getCredentials());
        return CodecUtil.md5(submitted).equals(encryptyed);
    }
}
