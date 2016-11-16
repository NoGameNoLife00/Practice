package plugin.security;

import java.util.Set;

/**
 * Smart Security�ӿ�
 */
public interface SmartSecurity {

    /**
     * �����û�����ȡ����
     * @param username
     * @return
     */
    String getPassword(String username);

    /**
     * �����û�����ȡ��ɫ����
     * @param username
     * @return
     */
    Set<String> getRoleNameSet(String username);

    /**
     * ���ݽ�ɫ����ȡȨ�޼���
     * @param roleName
     * @return
     */
    Set<String> getPermissionNameSet(String roleName);
}
