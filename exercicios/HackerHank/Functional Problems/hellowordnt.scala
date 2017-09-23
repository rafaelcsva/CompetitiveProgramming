object solution{
    
    def f(n:Int) : Unit = {
        if(n > 0){
            println("Hello World\n");

            f(n-1);
        }
    }


    def main(args: Array[String]) {
        val sc = new java.util.Scanner (System.in);
        var n = sc.nextInt();
        
        f(n)
    }
   
}
