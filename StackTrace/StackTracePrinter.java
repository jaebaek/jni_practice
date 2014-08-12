import java.lang.*;

class StackTracePrinter {
    public void printStackTrace() {
        final StackTraceElement[] ste = Thread.currentThread().getStackTrace();
        for (StackTraceElement s : ste) {
            System.out.println(s.getClassName()
                    +"#"+s.getMethodName());
        }
    }
}
