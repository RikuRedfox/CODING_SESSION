Question q1;
Question q2;
Question q3;
Question q4;
Question q5;
Question q6;
Question q7;
Question q8;
Question q9;
Question q10;

void language(){
    // first int is the position of the correct answer the second int are the score you will get.
    std::cout << "Oh! Language. Goodluck!\n\n";
    q1.setValues("Q : According to dictionary entries, which language has the largest number of words (more than 200,000 words)?",
                 "Chinese", "English", "Spanish", "Korea", 2, 10);
    q2.setValues("Q : Which language has the most native speakers in the world, with more than 900 million people?",
                 "Mandarin Chinese", "English", "Spanish", "Latin", 1, 10);
    q3.setValues("Q : Which of the following languages is related to Spanish the most?",
                 "Danish", "English", "Tagalog", "Italian", 4, 10);
    q4.setValues("Q : Which of the following language has no alphabet?",
                 "Korean", "Japanese", "Latin", "Chinese", 4, 10);
    q5.setValues("Q : What is the main difference between a language and a dialect?",
                 "A dialect is only spoken in some regions of a nation", "A language has a written form, while a dialect does not have", "People of different dialects of a language can understand each other, while people of two different language cannot", "None of the choices", 3, 10);
    q6.setValues("Q : Grammatical gender is how the language deals with nouns. Choose the right list with language from the most to least grammatical genders?",
                 "German, French, English", "Frenchm English, German", "English German, French", "German, French, Latin", 1, 10);
    q7.setValues("Q : What is the most common word order in most languages in the world?",
                 "Subject - Object - Verb", "Object - Verb - Object", "Subject - Verb - Object", "None of the choices", 1, 10);
    q8.setValues("Q : What is a possible reason why a language may disappear?",
                 "People choose to learn language with high prestige to get better opportunities", "People choose to learn more superior languages, which are inherently better", "Pople choose to learn easier language with simple grammars or pronunciations", "All of above", 1, 10);
    q9.setValues("Q : What is a dead language?",
                 "A language that is not officially recognised by any goverment", "A language that no one likes it", "A language that has no speakers anymore", "A language that is not the native language of any community", 3, 10);
    q10.setValues("Q : Which term refers to special expressions or words used by a group or profession that are difficult for others to understand?",
                  "Slang", "Jargon", "Dialect", "Sign Language", 2, 10);
}
void mathematics(){
    // first int is the position of the correct answer the second int are the correct score.
    std::cout << "Oh! Mathematics. Goodluck!\n\n";
    q1.setValues("Q : What is the total of all the internal angles of a triangle?",
                 "360°", "90°", "45°", "180°", 4, 10);
    q2.setValues("Q : True or false! A concave shape curves outwards.",
                 "True", "False", "- - -", "- - -", 2, 10);
    q3.setValues("Q : What is the name given to a straight line touching a circle?",
                 "A Radius", "A Tangent", "A Diameter", "A Chord", 2, 10);
    q4.setValues("Q : What is the value of Pi to four decimal places?",
                 "3.1427", "3.1546", "3.2416", "3.1416", 4, 10);
    q5.setValues("Q : What is the prime number closest to 100?",
                 "101", "99", "97", "95", 1, 10);
    q6.setValues("Q : What is the value of e?",
                 "APPROXIMATELY 2.717", "APPROXIMATELY 2.616", "APPROXIMATELY 2.716", "APPROXIMATELY 2.016", 3, 10);
    q7.setValues("Q : Three people all tell lies one third of the time. There is a coin flip that they all see, and all say is \"heads\". What’s the probability it is actually \"heads\"?",
                 "3/9", "8/9", "6/9", "1/9", 2, 10);
    q8.setValues("Q : At a party everyone shook hands with everyone else. In total, there were 66 handshakes. How many people were at the party?",
                 "12", "9", "11", "13", 1, 10);
    q9.setValues("Q : A hen and a half lays an egg and a half in a day and a half. How many eggs does one hen lay in a single day?",
                 "4/6 of an egg", "1/3 of an egg", "2/3 of an egg", "1/4 of an egg", 3, 10);
    q10.setValues("Q : What is the volume of a cube that has sides of 7cm?",
                  "313cm²", "333cm²", "343cm²", "303cm²", 3, 10);
}
void science(){
    // first int is the position of the correct answer the second int are the correct score.
    std::cout << "Oh! Science. Goodluck!\n\n";
    q1.setValues("Q : Humans and Chimpanzees share roughly how much DNA?",
                 "98%", "99%", "96%", "100%", 1, 10);
    q2.setValues("Q : What is the heaviest organ in the human body?",
                 "Lungs", "Heart", "Liver", "Brain", 3, 10);
    q3.setValues("Q : What is the only planet that spins clockwise?",
                 "Saturn", "Mars", "Earth", "Venus", 4, 10);
    q4.setValues("Q : How often does Halley's comet appear in the sky?",
                 "Every 70-72 years", "Every 69-70 years", "Every 75-76 years", "Every 74-75 years", 3, 10);
    q5.setValues("Q : How many planets in our solar system have moons?",
                 "6", "5", "7", "3", 1, 10);
    q6.setValues("Q : The brain is divided into how many lobes?",
                 "4", "8", "6", "2", 3, 10);
    q7.setValues("Q : How many constellations are in the night sky?",
                 "80", "90", "88", "87", 3, 10);
    q8.setValues("Q : What metal is the best conductor of electricity?",
                 "Iron", "Aluminium", "Silver", "Copper", 3, 10);
    q9.setValues("Q : What type of doctor is Stephen Strange?",
                 "Neurosurgeon", "Psychiatrists", "Neurologist", "Anesthesiologists", 1, 10);
    q10.setValues("Q : True or False! Lower tension on a tennis racquet produces more control and less power.",
                  "True", "False", "- - -", "- - -", 2, 10);
}
void history(){
    // first int is the position of the correct answer the second int are the correct score.
    std::cout << "Oh! History. Goodluck!\n\n";
    q1.setValues("Q : What year was the first iPhone released?",
                 "2007", "2005", "2006", "2008", 1, 10);
    q2.setValues("Q : What year did the Berlin Wall fall?",
                 "1992", "1987", "1989", "1990", 3, 10);
    q3.setValues("Q : What year was Facebook created?",
                 "2010", "2005", "2004", "2001", 3, 10);
    q4.setValues("Q : Who is the king of the Olympian gods in Greek mythology?",
                 "Hermes", "Apollo", "Zeus", "Ares", 3, 10);
    q5.setValues("Q : When did Alexander the Great conquer Egypt?",
                 "333 BC", "332 BC", "330 BC", "309 BC", 2, 10);
    q6.setValues("Q : Where is the Pyramid of the Sun located?",
                 "Cairo, Egypt", "Giza, Egypt", "Puebia, Mexico", "Taotihuacuan, Mexico", 4, 10);
    q7.setValues("Q : Which fabric was invented in Ancient China?",
                 "Silk", "Yarn", "Cotton", "Wool", 1, 10);
    q8.setValues("Q : When did the construction of the Great Wall of China begin?",
                 "7th century BC", "4th century BC", "9th century BC", "1st century BC", 1, 10);
    q9.setValues("Q : Where did Albert Einstein live before moving to the United States?",
                 "Dutch", "Swedish", "France", "Germany", 4, 10);
    q10.setValues("Q : During which war was a Christmas Truce called?",
                  "World War II", "World War I", "Cold War", "American Civil War", 2, 10);
}
void computers(){
    // first int is the position of the correct answer the second int are the correct score.
    std::cout << "Oh! Computers. Goodluck!\n\n";
    q1.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q2.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q3.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q4.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q5.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q6.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q7.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q8.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q9.setValues("Q : ",
                 "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
    q10.setValues("Q : ",
                  "Answer 1", "Answer 2", "Answer 3", "Answer 4", 3, 10);
}