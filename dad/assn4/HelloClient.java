package assn4;

import java.rmi.Naming;

public class HelloClient {
	public static void main(String[] args) {
		try {
			HelloWorld obj = (HelloWorld) Naming.lookup("//" + "127.0.0.1:1515" + "/HelloWorld");
			System.out.println("Message from server: " + obj.hello());
		} catch (Exception ex) {
			System.out.println("Exception: " + ex.getMessage());
		}
	}
}