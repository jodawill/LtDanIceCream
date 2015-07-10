#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Set the tax rate at 7%
#define TAXRATE		0.07
// Set discont rate to 10%
#define DISCOUNT	0.1

// Ice cream containers
#define CONE		1
#define WAFFLECONE	2
#define CUP		3

// Ice cream flavors
#define VANILLA		1
#define CHOCOLATE	2
#define CHERRYCORDIAL	3
#define ROCKYROAD	4
#define COOKIES		5

// Soda flavors
#define COLA		1
#define LEMONLIME	2
#define ROOTBEER	3

// Milk types
#define TWOPERC		1
#define SKIM		2
#define WHOLE		3

// Menu item types
#define ICECREAM	'i'
#define MILKSHAKE	'm'
#define FLOAT		'f'
#define SODA		's'
#define RECEIPT		'r'
#define QUIT		'q'

class IceCream {
 public:
  // If false, only request one scoop.
  bool doubleScoop;

  // Stores the flavors of scoops 0 and 1 (if applicable)
  int flavors[2];

  // A container could be a CONE, WAFFLECONE, or CUP
  int container;

  // Calculate and store the price of this item
  float price;
  void calc() {
   if (doubleScoop) {
    price = 3.5;
   } else {
    price = 2;
   }
   if (container == WAFFLECONE) {
    price += 0.5;
   }
  }
};

class Milkshake {
 public:
  // Could be any of the available ice cream flavors
  int flavor;

  // Choose 2%, skim, or whole milk
  int milk;

  // Whether the customer gets a discount for this item
  bool discount;

  // Calculate and store the price
  float price;
  void calc() {
   price = 4;
   if (discount) price -= price * DISCOUNT;
  }
};

class Float {
 public:
  // Number of scoops
  int scoops;

  // Flavor of each scoop
  int flavors[64];

  // Flavor of soda
  int sodaFlavor;

  // Whether this item is discounted
  bool discount;

  // Calculate and store the price
  float price;
  void calc() {
   price = 2 * scoops;
   if (discount) price -= price * DISCOUNT;
  }
};

void print_menu() {
 cout << endl
      << "MENU" << endl
      << "Available Flavors:" << endl
      << "(1) Vanilla (2) Chocolate (3) Cherry Cordial (4) Rocky Road (5) Cookies and Cream" << endl
      << "(1) Cola (2) Lemon-Lime (3) Root Beer" << endl
      << endl
      << "(i)  Ice Cream" << endl
      << "     One Scoop $2  Two Scoops $3.50" << endl
      << "     Available in a cake cone, cup, or waffle cone (50¢ extra)" << endl
      << endl
      << "(m) Milkshakes" << endl
      << "    Available in any one of our ice cream flavors" << endl
      << "    2%, skim, or whole milk" << endl
      << "    $4" << endl
      << endl
      << "(f) Floats:" << endl
      << "    Available in any of our soda flavors" << endl
      << "    $2 per scoop" << endl
      << endl
      << "Print (r)eceipt" << endl
      << endl
      << "$ ";
}

// Print a horizontal rule of length `max`
void hr(int max) {
 for (int i = 0; i < max; i++) cout << "-";
 cout << endl;
}

void push_space() {
 for (int i = 0; i < 30; i++) cout << " ";
}

float print_receipt(vector<IceCream>* icecreams,vector<Milkshake>* milkshakes,vector<Float>* floats) {
 float total,subtotal = 0;

 cout << "\n\n\n\n";
 hr(40);
 cout << "          LT. DAN'S ICE CREAM" << endl;
 hr(40);
 cout << endl;

 // We'll start off by printing all of the ice cream cones
 for (int i = 0; i < icecreams->size(); i++) {
  for (int j = 0; j < icecreams->at(i).doubleScoop + 1; j++) {
   switch (icecreams->at(i).flavors[j]) {
    case VANILLA: {
     cout << "VAN ";
     break;
    }
    case CHOCOLATE: {
     cout << "CHOC ";
     break;
    }
    case CHERRYCORDIAL: {
     cout << "CHRYCORD ";
     break;
    }
    case ROCKYROAD: {
     cout << "RCKYRD ";
     break;
    }
    case COOKIES: {
     cout << "CKSCRM ";
     break;
    }
    default: {
     cout << "UNKWN ";
     break;
    }
   }
  }
  cout << "ICE CREAM ";
  switch (icecreams->at(i).container) {
   case CONE: {
    cout << "CONE";
    break;
   }
   case WAFFLECONE: {
    cout << "WFLCON";
    break;
   }
   case CUP: {
    cout << "CUP";
    break;
   }
   default: {
    cout << "UNKWN";
    break;
   }
  }
  cout << endl;
  // Print the prices and add them to the subtotal.
  push_space();
  cout << "$" << fixed << setprecision(2) << icecreams->at(i).price << endl;
  subtotal += icecreams->at(i).price;
 }

 // Now print the milkshakes
 for (int i = 0; i < milkshakes->size(); i++) {
  switch (milkshakes->at(i).flavor) {
   case VANILLA: {
    cout << "VAN ";
    break;
   }
   case CHOCOLATE: {
    cout << "CHOC ";
    break;
   }
   case CHERRYCORDIAL: {
    cout << "CHRYCORD ";
    break;
   }
   case ROCKYROAD: {
    cout << "RCKYRD ";
    break;
   }
   case COOKIES: {
    cout << "CKSCRM ";
    break;
   }
   default: {
    cout << "UNKWN ";
    break;
   }
  }
  cout << "MILKSHAKE ";
  switch (milkshakes->at(i).milk) {
   case TWOPERC: {
    cout << "2%";
    break;
   }
   case SKIM: {
    cout << "SKIM";
    break;
   }
   case WHOLE: {
    cout << "WHOLE";
    break;
   }
   default: {
    cout << "UNKWN";
    break;
   }
  }
  cout << endl;

  // Print the prices and add them to the subtotal
  push_space();
  cout << "$" << fixed << setprecision(2) << milkshakes->at(i).price << endl;
  subtotal += milkshakes->at(i).price;
 }

 // Now print the floats
 for (int i = 0; i < floats->size(); i++) {
  switch (floats->at(i).sodaFlavor) {
   case COLA: {
    cout << "COLA ";
    break;
   }
   case LEMONLIME: {
    cout << "LMNLIM ";
    break;
   }
   case ROOTBEER: {
    cout << "RTBR ";
    break;
   }
   default: {
    cout << "UNKWN ";
    break;
   }
  }
  for (int j = 0; j < floats->at(i).scoops; j++) {
   switch (floats->at(i).flavors[j]) {
    case VANILLA: {
     cout << "VAN ";
     break;
    }
    case CHOCOLATE: {
     cout << "CHOC ";
     break;
    }
    case CHERRYCORDIAL: {
     cout << "CHRYCORD ";
     break;
    }
    case ROCKYROAD: {
     cout << "RCKYRD ";
     break;
    }
    case COOKIES: {
     cout << "CKSCRM ";
     break;
    }
    default: {
     cout << "UNKWN ";
     break;
    }
   }
  }
  cout << "FLOAT" << endl;

  // Print the prices and add them to the subtotal
  push_space();
  cout << "$" << fixed << setprecision(2) << floats->at(i).price << endl;
  subtotal += floats->at(i).price;
 }
 

 // Print total
 total = subtotal + subtotal * TAXRATE;
 cout << "\n\nSUBTOTAL: $" << fixed << setprecision(2) << subtotal << endl
      << "TAX:      $" << subtotal * TAXRATE << endl
      << "TOTAL:    $" << total << endl;
 return total;
}

int main() {
 float subtotal= 0;

 // Vectors containing the menu objects
 vector<IceCream> icecreams;
 vector<Milkshake> milkshakes;
 vector<Float> floats;

 hr(45);
 cout << "Welcome to Lt. Dan's Ice Cream and Soda Shop!" << endl;
 hr(45);
 // Print the menu and wait for a command
 for (char in = '\0'; in != QUIT; cin >> in) {
  switch (in) {
   case ICECREAM: {
    // Add ice cream to order 
    char doubleScoop;
    int container,flavors;
    IceCream tmp;
    cout << "Would you like a second scoop? (y/n) ";
    cin >> doubleScoop;
    tmp.doubleScoop = (doubleScoop == 'y');
    cout << "What flavor would you like on your first scoop? (1-5) ";
    cin >> flavors;
    tmp.flavors[0] = flavors;
    if (tmp.doubleScoop) {
     cout << "What flavor would you like on your second scoop? (1-5) ";
     cin >> flavors;
     tmp.flavors[1] = flavors;
    }
    cout << "Would you like a (1) cake cone (2) waffle cone or (3) cup? ";
    cin >> container;
    tmp.container = container;
    cout << "Discounts are not available for this item." << endl;
    // Calculate the price of this item
    tmp.calc();
    icecreams.push_back(tmp);
    break;
   }
   case MILKSHAKE: {
    // Add milkshake to order
    char discount;
    int flavor,milk;
    Milkshake tmp;
    cout << "What flavor of milkshake would you like? (1-5) ";
    cin >> flavor;
    tmp.flavor = flavor;
    cout << "Would you like (1) 2% (2) skim or (3) whole milk? ";
    cin >> milk;
    tmp.milk = milk;
    cout << "Do you have a coupon for this item? (y/n) ";
    cin >> discount;
    tmp.discount = (discount == 'y');
    tmp.calc();
    milkshakes.push_back(tmp);
    break;
   }
   case FLOAT: {
    // Add float to order
    char discount;
    int flavor,scoops;
    Float tmp;
    cout << "What flavor of soda would you like? (1-3) ";
    cin >> flavor;
    tmp.sodaFlavor = flavor;
    cout << "How many scoops would you like? ";
    cin >> scoops;
    tmp.scoops = scoops;
    for (int i = 0; i < scoops; i++) {
     cout << "What flavor of ice cream would you like for scoop #" << i + 1 << "? (1-5) ";
     cin >> flavor;
     tmp.flavors[i] = flavor;
    }
    cout << "Do you have a coupon for this item? (y/n) ";
    cin >> discount;
    tmp.discount = (discount == 'y');
    tmp.calc();
    floats.push_back(tmp);
    break;
   }
   case RECEIPT: {
    // Print receipt
    print_receipt(&icecreams,&milkshakes,&floats);
    return 0;
   }
  }
  print_menu();
 }

 return 0;
}

