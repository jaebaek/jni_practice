public class StackTrace {
    static {
        System.loadLibrary("StackTrace");
    }

    private native void do_print_stack();

    private void stack_content_1() {
        do_print_stack();
    }

    private void stack_content_2() {
        stack_content_1();
    }

    public static void main (String [] args) {
        (new StackTrace()).stack_content_2();
    }
}
