public class JniTest {
	static {
		System.load("/Users/yabinh/Documents/workspace/Hello/src/libJniTest.jnilib");
	}
	
	// Declare nativ method.
	public native void sayHello();
	public static void main(String[] args) {
		JniTest test = new JniTest();
		test.sayHello();
	}
}
