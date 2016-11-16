package com.bugcoding.smart4j.plugin.security.tag;

import org.apache.shiro.subject.Subject;
import org.apache.shiro.web.tags.RoleTag;

import java.util.Arrays;

/**
 * �жϵ�ǰ�û��Ƿ�ӵ���������н�ɫ
 */
public class HasAllRolesTag extends RoleTag {

    private static final String ROLE_NAMES_DELIMITER = ",";
    @Override
    protected boolean showTagBody(String roleNames) {
        boolean hasAllRole = false;
        Subject subject = getSubject();
        if (subject != null) {
            if (subject.hasAllRoles(Arrays.asList(roleNames.split(ROLE_NAMES_DELIMITER)))) {
                hasAllRole = true;
            }
        }
        return  hasAllRole;
    }
}
