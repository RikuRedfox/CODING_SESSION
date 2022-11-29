#include <iostream>
#include <string>
using std::cout, std::endl, std::cin, std::getline;

/*
    Mini game called mad libs | 6.7.2022 | 6.23.2022 | 9.19.2022
    story link https://tinyurl.com/36se7sdu

    A one-act play to be performaed by two { plural noun 1 inputs[5] } in this
   room. PATIENT: Thank you so very much for seeing me. Doctor { person name
   inputs[0] }, on such { adjective1 inputs[7] } notice. DENTIST: What is your
   problem, young { noun1 inputs[9] }? PATIENT: I have a pain in my upper {
   noun2 inputs[10] }, which is giving me a severe { bodyPart inputs[3] }ache.
    DENTIST: Let me take a look. Open your { bodyPart inputs[4] } wide.
    Good. Now I'm going to  tap your { pluralNoun2 inputs[6] } with my { noun3
   inputs[11] } PATIENT: Shoudn't you give me a/an { noun4 inputs[12] } killer?
    DENTIST: It's not neccessary yet, { exclamation inputs[2] } I think I see
    a/an { noun5 inputs[13] } in your upper { noun6 inputs[14] }
    PATIENT: Are you going to pull my { noun7 inputs[15] } out?
    DENTIST: No, I'm goint to { verb inputs[1] } your tooth and put in
    a temporary { noun8 inputs[16] } .
    PATIENT: When do I come back for the { adjective2 inputs[8] } filling?
    DENTIST: A day after I cash your { noun9 inputs[17] }.
*/

std::string person_name, verb, exclamation, body_part[2], plural_noun[2],
    adjective[2], noun[9];
void new_inputs() { // personName 0, verb 1, exclamation 2, body Part 3-4,
                    // pluralNoun 5-6, adjective 7-8, noun  9 - 17

  cout << "\nEnter a person's name : ";
  cin >> person_name;
  cout << endl;

  cout << "Enter a verb : ";
  cin >> verb;
  cout << endl;

  cout << "Enter an exlamation : ";
  cin >> exclamation;
  cout << endl;

  size_t i{0}, j{1};
  cout << "Enter two body parts : \n";
  for (; i < 2; i++) {
    cout << "[" << j << "]"
         << " : ";
    cin >> body_part[i];
    j++;
  }
  i = 0, j = 1;

  cout << "\nEnter two plural nouns : \n";
  for (; i < 2; i++) {
    cout << "[" << j << "]"
         << " : ";
    cin >> plural_noun[i];
    j++;
  }
  i = 0, j = 1;

  cout << "\nEnter two adjectives : \n";
  for (; i < 2; i++) {
    cout << "[" << j << "]"
         << " : ";
    cin >> adjective[i];
    j++;
  }
  i = 0, j = 1;

  cout << "\nEnter eight nouns : \n";
  for (; i < 9; i++) {
    cout << "[" << j << "]"
         << " : ";
    cin >> noun[i];
    j++;
  }
}

void new_outputs() {
  cout << "A one-act play to be performaed by two "
       << plural_noun[0] /*plural noun*/ << " in this room.\n";
  cout << "PATIENT: Thank you so very much for seeing me.\n";
  cout << "Doctor " << person_name /*person name*/ << ", on such "
       << adjective[0] /*adjective*/ << " notice.\n";
  cout << "DENTIST: What is your problem, young " << noun[0] /*noun*/ << "?\n";
  cout << "PATIENT: I have a pain in my upper "
       << noun[1] /*noun*/ << ", which is\n";
  cout << "giving me a severe " << body_part[0] /*body part*/ << " ache.\n";
  cout << "DENTIST: Let me take a look. Open your "
       << body_part[1] /*body part*/ << " wide.\n";
  cout << "Good. Now I'm going to  tap your "
       << plural_noun[1] /*plural noun*/ << " with my " << noun[2] << endl;
  cout << "PATIENT: Shoudn't you give me a/an "
       << noun[3] /*noun*/ << " killer?\n";
  cout << "DENTIST: It's not neccessary yet, "
       << exclamation /*exclamation*/ << " I think I see\n";
  cout << "a/an " << noun[4] /*noun*/ << " in your upper "
       << noun[5] /*noun*/ << endl;
  cout << "PATIENT: Are you going to pull my " << noun[6] /*noun*/ << " out?\n";
  cout << "DENTIST: No, I'm goint to "
       << verb /*verb*/ << " your tooth and put in\n";
  cout << "a temporary " << noun[7] /*noun*/ << "." << endl;
  cout << "PATIENT: When do I come back for the "
       << adjective[1] /*adjective*/ << " filling?\n";
  cout << "DENTIST: A day after I cash your " << noun[8] /*noun*/ << ".";
}

int main() {
  while (true) {
    cout << "Press Enter to continue . . . ";
    cin.get();

    new_inputs();
    cout << endl << endl;
    new_outputs();

    cout << "\n\nDo you want to try this again? [1]YES [0]NO\n>> ";
    int dec;
    cin >> dec;
    if (dec != 1) {
      break;
    }
  }
  cout << "\n\nThank you for trying this mini game. q(≧▽≦q)\n";
  return 0;
}