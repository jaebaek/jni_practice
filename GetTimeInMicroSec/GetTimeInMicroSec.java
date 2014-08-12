class GetTimeInMicroSec {
    static {
        System.loadLibrary("GetTimeInMicroSec");
    }

    private native long [] get_time_in_microsec();

    public static void main (String [] args) {
        long [] now = (new GetTimeInMicroSec()).get_time_in_microsec();
        System.out.println("current time = " + now[0] + "." + now[1]);
    }
}
