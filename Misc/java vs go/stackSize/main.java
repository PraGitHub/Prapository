import java.io.*;
public class main {

    static String fileName;
    static int count = -1;
    static FileOutputStream result = null;

    public static void stackOverflow()throws IOException{
        count++;
        //boolean proceed = true;
        if(count%1000 == 0){
            try{
                result = new FileOutputStream("./results/java/stackOverflow.java.result."+fileName);
            }
            catch(FileNotFoundException ex){
                //proceed = false;
            }
//            if(proceed){
                //System.out.print("stackOverflow :: writing count");
                result.write(new Integer(count).toString().getBytes());
                result.close();
            //}
        }
        stackOverflow();
    }

   public static void main(String args[]) {  
      fileName = args[0];
      File file = new File("./results/java/stackOverflow.java.result."+fileName);
      try{
        file.createNewFile();
        stackOverflow();
      }
      catch(IOException ex){
        //System.out.println("main :: IOException");
      }
   }
}