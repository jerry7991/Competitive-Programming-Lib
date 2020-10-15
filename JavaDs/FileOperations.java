import java.io.*;
import java.util.*;

class FileOperations{

	static int choice;
	File f,f1;
	static Scanner scnr=new Scanner(System.in);

	public static void main(String args[]){
		while(true){
			System.out.println("1.Create File");
			System.out.println("2.Rename File");
			System.out.println("3.Delete File");
			System.out.println("4.File Infomation");
			System.out.println("6.Copy File");
			System.out.println("5.Exit");

			FileOperations fo=new FileOperations();
			choice=scnr.nextInt();
			scnr.nextLine();

			switch(choice){
				case 1:try{fo.create_File();}
				catch(Exception ioe){ioe.printStackTrace();}
				break;

				case 2:try{fo.rename_File();}
				catch(Exception ioe){ioe.printStackTrace();}
				break;

				case 3:try{fo.delete_File();}
				catch(Exception ioe){ioe.printStackTrace();}
				break;

				case 4:try{fo.getInfo();}
				catch(Exception ioe){ioe.printStackTrace();}
				break;

				//case 5:try{fo.copy_File();}catch(IOException ioe){ioe.printStackTrace();}
				//break;

				case 5:System.exit(0);
				break;

				default:System.out.println("Enter a valid choice...");
			}
			
		}

	}

	//1.CreateFile
	public void create_File() throws IOException{
		System.out.print("Enter file name : ");
		String fn=scnr.nextLine();
		f=new File(fn);
		f.createNewFile();
		if(f.exists())
			System.out.println("\nFile Created Successfully");
		else
			System.out.println("Error in creating new file");
	}

	//2.RenameFile
	public void rename_File(){
		System.out.print("Enter the new name : ");
		String fn1=scnr.nextLine();
		f1=new File(fn1);
		if(f.renameTo(f1))
			System.out.println("\nName changed successfully");
		else
			System.out.println("Error in changing file name");
	}

	//3.deleteFile
	public void delete_File(){
		System.out.println("Are you sure you want to delete file :"+f);
		String consent=scnr.nextLine();
		String y="yes";
		String no="no";
		//boolean d;
		if(consent.equals(y)){
			if(f.delete())
				System.out.println("File deleted successfully");
			else
				System.out.println("Error deleting file");
		}
	}

	//4.getInfo
	public void getInfo(){
		System.out.println("File Name : "+f.getName());
		System.out.println("File Location : "+f.getPath());
		System.out.println("Parent directory : "+f.getParent());
		System.out.println("Last Modified : "+f.lastModified());
		System.out.println("File Length : "+f.length());
	}

	//5.getInfo
	/*public void copy_File(){
		FileInputStream fis=new FileInputStream(f1);
		System.out.println("Enter The name of copied content file :")
		String fd=scnr.nextLine();
		File fd1=new File(fd);
		FileOutputStream fos=new FileOutputStream(fd1);
		if(fd1.createNewFile()){
			int i;
			while((i=fis.read())!=-1){
				fos.write((byte)i);
		    }
		}
		else{
			System.out.println("Error in copying");
		}    
	}
	*/
}