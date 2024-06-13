import java.util.*;

class User {
    String name;
    int dateOfBirth;
    String Address;
    int PAN;

    public User() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name:");
        name = sc.nextLine();
        System.out.println("Enter Date of Birth (YYYYMMDD format)");
        dateOfBirth = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Address");
        Address = sc.nextLine();
        System.out.println("Enter PAN:");
        PAN = sc.nextInt();
        sc.nextLine();
    }

}

class SuperUser extends User {
    int SuperUserID;
    int password;
    int dateOfJoining;
    int salary;
    int permissibleOperations;

    public SuperUser() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Super user ID:");
        SuperUserID = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter password:");
        password = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Date of Joining (YYYYMMDD format)");
        dateOfJoining = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter salary:");
        salary = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter no. of permissible operations:");
        permissibleOperations = sc.nextInt();
        sc.nextLine();
    }

    public void addNewStock(Item i) {
        Sys.items.add(i);
        System.out.println("Item added successfully!");
    }

    public void deleteStock(int itemCode) {
        for (Item i : Sys.items) {
            if (i.itemCode == itemCode && i.AvailableQty != 0) {
                Sys.items.remove(i);
                System.out.println("Item removed successfully!");
                break;
            }
        }
    }

    public void modifyStock(int itemCode) {
        Scanner sc = new Scanner(System.in);
        for (Item i : Sys.items) {
            if (i.itemCode == itemCode) {
                int choice;
                System.out.println("Enter 1 to update price");
                System.out.println("Enter 2 to update available quantity");
                choice = sc.nextInt();
                sc.nextLine();
                if (choice == 1) {
                    System.out.println("Enter new price:");
                    int price = sc.nextInt();
                    sc.nextLine();
                    i.price = price;
                    System.out.println("Price updated successfully!");
                } else if (choice == 2) {
                    System.out.println("Enter new available quantity");
                    int qty = sc.nextInt();
                    sc.nextLine();
                    i.AvailableQty = qty;
                    System.out.println("Quantity updated successfully!");
                } else {
                    System.out.println("Wrong choice!");
                }
                break;
            }
        }
    }

}

class NormalUser extends User {
    int userID;
    int dateOfJoining;
    int salary;
    int dutyHourPerDay;

    public NormalUser() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter user ID:");
        userID = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Date of Joining (YYYYMMDD format)");
        dateOfJoining = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter salary:");
        salary = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter duty hour per day:");
        dutyHourPerDay = sc.nextInt();
        sc.nextLine();
    }


    public void sellItem(int itemCode, int quantity) {
        Scanner sc = new Scanner(System.in);
        for (Item i : Sys.items) {
            if (i.itemCode == itemCode) {
                Sell s = new Sell(1);
                i.AvailableQty = i.AvailableQty - quantity;
                System.out.println("Enter date of sell(YYYYMMDD format)");
                s.dateOfSell = sc.nextInt();
                sc.nextLine();
                s.itemCode = itemCode;
                s.quantity = quantity;
                s.totalAmount = i.price * quantity;
                Sys.sell.add(s);
                System.out.println("Item sold successfully!");
                break;
            }
        }
    }

    public void returnItem(int itemCode, int quantity) {
        Scanner sc = new Scanner(System.in);
        if (itemCode % 2 == 0) {
            System.out.println("It is a consumable item!Cannot be returned");
        } else {
            for (Item i : Sys.items) {
                if (i.itemCode == itemCode) {
                    Return r = new Return();
                    i.AvailableQty = i.AvailableQty + quantity;
                    System.out.println("Enter date of return(YYYYMMDD format)");
                    r.dateOfReturn = sc.nextInt();
                    sc.nextLine();
                    r.itemCode = itemCode;
                    r.quantity = quantity;
                    r.returnAmount = i.price * quantity;
                    Sys.ret.add(r);
                    System.out.println("Item returned successfully!");
                    break;
                }
            }
        }
    }

    public void displayStock(int itemCode) {
        for (Item i : Sys.items) {
            if (i.itemCode == itemCode) {
                if (itemCode % 2 == 0) {
                    System.out.println("Consumbale item");
                } else {
                    System.out.println("Non-Consumbale item");
                }
                System.out.println("Item Code: " + i.itemCode);
                System.out.println("Price: " + i.price);
                System.out.println("Available quantity: " + i.AvailableQty);
            }
        }
    }

    public void displayStockSell(int itemCode) {
        for (Sell i : Sys.sell) {
            if (i.itemCode == itemCode) {
                if (itemCode % 2 == 0) {
                    System.out.println("Consumbale item");
                } else {
                    System.out.println("Non-Consumbale item");
                }
                System.out.println("Item Code: " + i.itemCode);
                System.out.println("Date Of sell(YYYYMMDD format): " + i.dateOfSell);
                System.out.println("Quantity sold: " + i.quantity);
                System.out.println("Total Amount: " + i.totalAmount);
            }
        }
    }


    public void displaySell(int startDate, int endDate) {
        for (Sell i : Sys.sell) {
            if (i.dateOfSell >= startDate && i.dateOfSell <= endDate) {
                displayStockSell(i.itemCode);
            }
        }
    }

    public void displayToBeExpiredItems(int m) {
        for (Item i : Sys.items) {
            if (i.itemCode % 2 == 0) {
                Consumables con = new Consumables(1);
                con = (Consumables) i;
                if (con.dateOfExpiry == m) {
                    displayStock(i.itemCode);
                }
            }
        }
    }

}

class Item {
    int itemCode;
    int price;
    int AvailableQty;

    public Item() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Item Code\nEven for consumables and odd for non-consumables:");
        itemCode = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter price:");
        price = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter available quantity:");
        AvailableQty = sc.nextInt();
        sc.nextLine();
    }

}

class Consumables extends Item {
    int dateOfExpiry;

    public Consumables(int i) {
    }

    public Consumables() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Item Code\nEven for consumables and odd for non-consumables:");
        itemCode = sc.nextInt();
        sc.nextLine();
        if (itemCode % 2 != 0) {
            System.out.println("Incorrect code for consumables");
            System.exit(0);
        }

        System.out.println("Enter price:");
        price = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter available quantity:");
        AvailableQty = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter date of expiry(MM format):");
        dateOfExpiry = sc.nextInt();
        sc.nextLine();
    }

}

class NonConsumables extends Item {
    int returnCount;

    public NonConsumables() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Item Code\nEven for consumables and odd for non-consumables:");
        itemCode = sc.nextInt();
        sc.nextLine();
        if (itemCode % 2 == 0) {
            System.out.println("Incorrect code for non-consumables");
            System.exit(0);
        }

        System.out.println("Enter price:");
        price = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter available quantity:");
        AvailableQty = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter return count:");
        returnCount = sc.nextInt();
        sc.nextLine();
    }
}


class Sell {
    int dateOfSell;
    int itemCode;
    int quantity;
    int totalAmount;

    public Sell() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter item code:");
        itemCode = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Date of Sell (YYYYMMDD format)");
        dateOfSell = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter quantity:");
        quantity = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter total amount:");
        totalAmount = sc.nextInt();
        sc.nextLine();
    }

    public Sell(int i) {
    }
}

class Return {
    int dateOfReturn;
    int itemCode;
    int quantity;
    int returnAmount;

    public Return() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter item code:");
        itemCode = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Date of Return (YYYYMMDD format)");
        dateOfReturn = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter quantity:");
        quantity = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter return amount:");
        returnAmount = sc.nextInt();
        sc.nextLine();
    }
}

class Sys {

    public static ArrayList<Item> items = new ArrayList<>();
    public static ArrayList<Sell> sell = new ArrayList<>();
    public static ArrayList<Return> ret = new ArrayList<>();

    public static ArrayList<NormalUser> norm = new ArrayList<>();

    public static ArrayList<SuperUser> sup = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        int c = 0;
        while (true) {
            System.out.println("MENU");
            System.out.println();
            System.out.println("1. Setup");
            System.out.println("2. SuperUser mode");
            System.out.println("3. NormalUser User mode");
            System.out.println("4. Exit");
            System.out.println();
            System.out.println("Enter your choice");
            choice = sc.nextInt();


            switch (choice) {
                case 1:
                    SuperUser s = new SuperUser();
                    System.out.println("Super User object created");
                    Sys.sup.add(s);
                    System.out.println("Enter number of NormalUser objects to be added:");
                    int num = sc.nextInt();
                    for (int i = 0; i < num; i++) {
                        NormalUser n = new NormalUser();
                        Sys.norm.add(n);
                    }
                    c = 1;
                    break;
                case 2:
                    if (c == 0) {
                        System.out.println("ERROR");
                        System.out.println("Choose set up first");
                        break;
                    } else {
                        System.out.println("Enter SuperUserID:");
                        int id = sc.nextInt();
                        System.out.println("Enter password:");
                        int pass = sc.nextInt();
                        if (Sys.sup.get(0).SuperUserID == id && Sys.sup.get(0).password == pass) {
                            int ch;

                            System.out.println("MENU");
                            System.out.println();
                            System.out.println("1. Add new Stock");
                            System.out.println("2. Delete Stock");
                            System.out.println("3. Modify Stock");
                            System.out.println("Enter choice");
                            ch = sc.nextInt();

                            switch (ch) {
                                case 1:
                                    Item i = new Item();
                                    Sys.sup.get(0).addNewStock(i);
                                    break;
                                case 2:
                                    System.out.println("enter item code to be deleted:");
                                    int code = sc.nextInt();
                                    Sys.sup.get(0).deleteStock(code);
                                    break;
                                case 3:
                                    System.out.println("enter item code to be updated:");
                                    code = sc.nextInt();
                                    Sys.sup.get(0).deleteStock(code);
                                    break;
                            }


                        } else {
                            System.out.println("Mismatch");
                        }
                        break;
                    }
                case 3:
                    if (c == 0) {
                        System.out.println("ERROR");
                        System.out.println("Choose set up first");
                        break;
                    } else {
                        System.out.println("Enter userId:");
                        int id = sc.nextInt();
                        for (NormalUser i : Sys.norm) {
                            if (i.userID == id) {
                                int ch;

                                System.out.println("MENU");
                                System.out.println();
                                System.out.println("1. Sell item");
                                System.out.println("2. Return item");
                                System.out.println("3. Display Stock");
                                System.out.println("4. Display to be expired items");
                                System.out.println("5. Display sell");
                                System.out.println("Enter choice");
                                ch = sc.nextInt();

                                switch (ch) {
                                    case 1:
                                        System.out.println("Enter itemcode and quantity to be sold:");
                                        int co = sc.nextInt();
                                        int q = sc.nextInt();
                                        i.sellItem(co, q);
                                        break;
                                    case 2:
                                        System.out.println("Enter itemcode and quantity to be returned:");
                                        co = sc.nextInt();
                                        q = sc.nextInt();
                                        i.returnItem(co, q);
                                        break;
                                    case 3:
                                        System.out.println("Enter itemcode to be displayed:");
                                        co = sc.nextInt();
                                        i.displayStock(co);
                                        break;
                                    case 4:
                                        System.out.println("Enter month to be expired in MM format:");
                                        int m = sc.nextInt();
                                        i.displayToBeExpiredItems(m);
                                        break;
                                    case 5:
                                        System.out.println("Enter start date(YYYYMMDD format)");
                                        int start = sc.nextInt();
                                        System.out.println("Enter end date(YYYYMMDD format)");
                                        int end = sc.nextInt();
                                        i.displaySell(start, end);
                                }

                            } else {
                                System.out.println("User does not exist");
                                break;
                            }
                        }
                        break;
                    }

                case 4:
                    System.out.println("Exiting...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong choice!");
            }
        }
    }
}