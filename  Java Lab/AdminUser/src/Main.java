import java.util.ArrayList;
import java.util.Scanner;

class User {
    public int userID;
    public String name;
    public int dateOfBirth;

    public String Address;
    public int PAN;
}

class Admin extends User {
    public int dateOfJoining;
    public int salary;
    public int permissibleOperations;


    public void addNewStock(Item item) {
        Main.itemArray.add(item);
    }

    public void deleteStock(int itemCode) {
        for (Item i : Main.itemArray) {
            if (i.itemCode == itemCode) {
                i.AvailableQty=0;
                Main.itemArray.remove(i);
                break;
            }
        }
    }

    public static void modifyStock(int itemCode) {
        for (Item i : Main.itemArray) {
            if (i.itemCode == itemCode) {
                System.out.println("Enter the new price: ");
                i.price = Main.sc.nextInt();
                Main.sc.nextLine();
                break;
            }
        }
    }

    public static void modifyStock(int itemCode, int qty) {
        for (Item i : Main.itemArray) {
            if (i.itemCode == itemCode) {
                i.AvailableQty += qty;
                break;
            }
        }
    }

}

class General extends User {
    public int dateOfJoining;
    public int salary;
    public int dutyHourPerDay;

    public void returnItem(int itemCode, int quantity) {
        boolean possible = true;
        for (Item i : Main.itemArray) {
            if (i.itemCode == itemCode) {
                if (i.getClass() == FoodItem.class) {
                    System.out.println("Cannot return a Food Item");
                    possible = false;
                    break;
                }
            }

        }

        if (possible) {
            Main.returnArray.add(new Return());
            Admin.modifyStock(itemCode, quantity);
        }


    }

    public void sellItem(int itemCode, int quantity) {
        boolean possible = true;
        for (Item i : Main.itemArray) {
            if (i.itemCode == itemCode) {
                Admin.modifyStock(itemCode, -quantity);
                Main.sellArray.add(new Sell());
            }

        }


    }
}


class Item {
    int itemCode;
    int price;
    int AvailableQty;
}

class FoodItem extends Item {
    public int dateOfExpiry;
}

class NonFoodItem extends Item {
    public int returnCount;
}

class Sell {
    public int dateOfSell;
    public int itemCode, quantity, totalAmount;

}

class Return {
    public int dateOfReturn;
    public int itemCode, quantity, returnAmount;
}


public class Main {
    public static Scanner sc = new Scanner(System.in);
    public static ArrayList<Item> itemArray;

    public static ArrayList<Sell> sellArray;
    public static ArrayList<Return> returnArray;

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}