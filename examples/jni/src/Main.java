public class Main {

    // Prototype de la fonction native
    public native static int quaranteDeux();
    public native static int fact(int n);

    static { // Chargement de la bibliothèque libtest.so
	System.loadLibrary("test");
    }

    public static void main(String[] args) {
	System.out.println(Main.quaranteDeux());
	System.out.println(Main.fact(5));
    }

}
