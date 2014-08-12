public class HelloWorld {
    static {
        System.loadLibrary("hello");
    }
    private native void sayHello();
    public static void main (String [] args) {
        new HelloWorld().sayHello();
    }
}
