package assn4;

import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class HelloServer extends UnicastRemoteObject implements HelloWorld {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public HelloServer() throws RemoteException {
		super();
	}

	public static void main(String[] args) {
		try {
			LocateRegistry.createRegistry(1515);
			HelloServer obj = new HelloServer();
			System.out.println("Server started");
			Naming.rebind("rmi://127.0.0.1:1515/HelloWorld", obj);
		} catch (Exception ex) {
			System.out.println("Exception: " + ex.getMessage());
		}
	}

	public String hello() throws RemoteException {
		System.out.println("Remote called hello()");
		return "Hello!!!";
	}

}