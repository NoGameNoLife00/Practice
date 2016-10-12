package com.bugcoding.chapter2.util;

import java.util.Map;

/**
 * Created by tao on 2016/10/12.
 */
public final class CollectionUtil {

    public static boolean isEmpty(Map<String, Object> map) {
        return map == null || map.isEmpty();
    }
}
