import java.awt.EventQueue;

public class Test1 {
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				new ObrazFrame();
			}
		});
	}
}
