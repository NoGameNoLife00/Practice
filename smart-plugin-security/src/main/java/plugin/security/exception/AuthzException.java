package plugin.security.exception;

/**
 * ��Ȩ�쳣����Ȩ����Чʱ�׳���
 */
public class AuthzException  extends RuntimeException{

    public AuthzException() {
        super();
    }

    public AuthzException(String message) {
        super(message);
    }

    public AuthzException(String message, Throwable cause) {
        super(message, cause);
    }

    public AuthzException(Throwable cause) {
        super(cause);
    }
}
