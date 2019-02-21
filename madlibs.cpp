/***************************
 ** Program: madlibs
 ** Author: Jeremiah Kramer
 ** Date: 3/14/17
 ** Description: This is a madlibs game with random noun/verb/adjective generation with 3 stories in total.
 ** Input: Number of story, word_file.
 ** Output: A Madlibs story.
 ***************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

/***************************
 ** Function: read_array
 ** Description: reads the input from the word_file and puts it into a 2d word array
 ** Parameters: char word[][40]
 ** Pre- Conditions: needs a word file to read from
 ** Post- Conditions: none
 ** Return: none
 **************************/
void read_array(char word[][40]){

	for (int i = 0; i < 75; i++){ //75 possible nouns/verbs/adjectives
		cin.getline(word[i], 40); //each word can be 30 characters long, so adjective and a space equals 10 characters (10 + 30 = 40)
	}
}

/***************************
 ** Function: noun_temp
 ** Description: reads from the word array if the line begins with a 'n' if so, it puts it into the temporary noun array
 ** Parameters: char word[][40], char *temp_noun[], int *tn
 ** Pre- Conditions: word array
 ** Post- Conditions: noun_array, nouns_array
 ** Return: none
 **************************/
void noun_temp(char word[][40], char *temp_noun[], int *tn){

	for (int i = 0; i < 75; i++){ //check the entire 2d array for noun
		if (word[i][0] == 'n'){
			temp_noun[*tn] = strchr(word[i], ' ') + 1; //put just the word into the temp_noun array (get rid of noun + space in beginning)
			*tn += 1;
		}
	}
}

/***************************
 ** Function: noun
 ** Description: reads from temp_noun array and puts it into nouns_array or noun_array
 ** Parameters: char *temp_noun[], char *noun_array[], char *nouns_array[], int *tn, int *n, int *s, int *length_noun
 ** Pre- Conditions: temp_noun array
 ** Post- Conditions: none
 ** Return: none
 **************************/
void noun(char *temp_noun[], char *noun_array[], char *nouns_array[], int *tn,  int *n, int *s, int *length_noun){

	for (int i = 0; i < *tn; i++){
		for (int j = 0; j < 30; j++){ //now 30 possible characters in word
			if (temp_noun[i][j] == 's' && temp_noun[i][j + 1] == '\0'){ //if it ends in s, put in nouns_array
				nouns_array[*s] = temp_noun[i];
				*s += 1;
				*length_noun = j;
			}
		}

		if (temp_noun[i][*length_noun] != 's'){ //if it doesn't end in s, put in noun_array
			noun_array[*n] = temp_noun[i];
			*n += 1;
		}
	}
}

/***************************
 ** Function: noun_complete
 ** Description: calls noun_temp and noun funcs
 ** Parameters: char word[][40], char *temp_noun[]|*noun_array[]|*nouns_array[], int *tn|*n|*s|*length_noun
 ** Pre- Conditions: noun_temp and noun
 ** Post- Conditions: finish
 ** Return: none
 **************************/
void noun_complete(char word[][40], char *temp_noun[], char *noun_array[], char *nouns_array[], int *tn, int *n, int *s, int *length_noun){

	noun_temp(word, temp_noun, tn);
	noun(temp_noun, noun_array, nouns_array, tn,  n, s, length_noun);
}

/***************************
 ** Function: verb_temp
 ** Description: reads from the word array if the line begins with a 'v' if so, it puts it into the temporary verb array
 ** Parameters: char word[][40], char *temp_verb[], int *tv
 ** Pre- Conditions: word array
 ** Post- Conditions: verb_array, verbing_array
 ** Return: none
 **************************/
void verb_temp(char word[][40], char *temp_verb[], int *tv){

	for (int i = 0; i < 75; i++){ //check the entire 2d arry for verb
		if (word[i][0] == 'v'){
			temp_verb[*tv] = strchr(word[i], ' ') + 1; //put just the word into the temp_verb array (get rid of verb + space in beginning)
			*tv += 1;
		}
	}
}

/***************************
 ** Function: verb
 ** Description: This program 
 reads from temp_verb array and puts it into verbing_array or verb_array
 ** Parameters: char *temp_verb], char *verb_array[], char *verbing_array[], int *tv, int *v, int *g, int *length_verb
 ** Pre- Conditions: temp_verb array
 ** Post- Conditions: none
 ** Return: none
 **************************/
void verb(char *temp_verb[], char *verb_array[], char *verbing_array[], int *tv, int *v, int *g, int *length_verb){

	for (int i = 0; i < *tv; i++){
		for (int j = 0; j < 30; j++){ //now 30 possible characters in word
			if (temp_verb[i][j] == 'i' && temp_verb[i][j + 1] == 'n' && temp_verb[i][j + 2] == 'g' && temp_verb[i][j + 3] == '\0'){ //if it ends in ing, put it into verbing_array
				verbing_array[*g] = temp_verb[i];
				*g += 1;
				*length_verb = j + 2; //compensate for ing
			}
		}
		if (temp_verb[i][*length_verb] != 'g'){ //if it doesn't end in ing, put it into verb_array
			verb_array[*v] = temp_verb[i];
			*v += 1;
		}
	}
}

/***************************
 ** Function: verb_complete
 ** Description: calls verb_temp and verb
 ** Parameters: char word[][40], char *temp_verb[]|*verb_array[]|*verbing_array[], int *tv|*v|*g|*length_verb
 ** Pre- Conditions: verb_temp and ver
 ** Post- Conditions: finish
 ** Return: none
 **************************/
void verb_complete(char word[][40], char *temp_verb[], char *verb_array[], char *verbing_array[], int *tv, int *v, int *g, int *length_verb){

	verb_temp(word, temp_verb, tv);
	verb(temp_verb, verb_array, verbing_array, tv, v, g, length_verb);	
}

/***************************
 ** Function: adjective_complete
 ** Description: reads from the word array if the line begins with a 'a' if so, it puts it into the adjective array
 ** Parameters: char word[][40], char *adjective_array[], int *a
 ** Pre- Conditions: word array
 ** Post- Conditions: finish
 ** Return: none
 **************************/
void adjective_complete(char word[][40], char *adjective_array[], int *a){

	for (int i = 0; i < 75; i++){ //check the entire 2d arry for verb
		if (word[i][0] == 'a'){
			adjective_array[*a] = strchr(word[i], ' ') + 1; //put just the word into the adjective array (get rid of adjective + space in beginning)
			*a += 1;
		}
	}
}

/***************************
 ** Function: finish
 ** Description: calls read_array, noun_complete, verb_complete, adjective_complete
 ** Parameters: char word[][40]|temp_noun[]|noun_array[]|nouns_array[]|verb_array[]|verbing_array[]|adjective_array[], int *tn|*n|*s|*tv|*v|*g|*a|*length_noun|*length_verb
 ** Pre- Conditions: read_array, noun_complete, verb_complete, adjective_complete
 ** Post- Conditions: main
 ** Return: none
 **************************/
void finish(char word[][40], char *temp_noun[], char *noun_array[], char *nouns_array[], char *temp_verb[], char *verb_array[], char *verbing_array[], char *adjective_array[], int *tn, int *n, int *s, int *tv, int *v, int *g, int *a, int *length_noun, int *length_verb){

	read_array(word);
	noun_complete(word, temp_noun, noun_array, nouns_array, tn, n, s, length_noun);
	verb_complete(word, temp_verb, verb_array, verbing_array, tv, v, g, length_verb);
	adjective_complete(word, adjective_array, a);
}

/***************************
 ** Function: story 1
 ** Description: randomizes integers with range depending on their specific word amount and prints the story with the random noun/verb/adjective
 ** Parameters: char *noun_array[]|*nouns_array[]|*verb_array[]|*verbing_array[]|*adjective_array[]|int *n|*s|*v|*g|*a
 ** Pre- Conditions: finish
 ** Post- Conditions: none
 ** Return: none
 **************************/
void story1(char *noun_array[], char *nouns_array[], char *verb_array[], char *verbing_array[], char *adjective_array[], int *n, int *s, int *v, int *g, int *a){

	int aa, b, c, d, e, f, gg, h, i, j, k, l; //note: these need to be separate variables or else the element in the array would be the same for all, and the words wouldn't vary
	srand(time(NULL));
	aa = rand() % *g; 
	b = rand() % *a;
	c = rand() % *g;
	d = rand() % *n;
	e = rand() % *n;
	f = rand() % *s;
	gg = rand() % *v;
	h = rand() % *s;
	i = rand() % *n;
	j = rand() % *v;
	k = rand() % *a;
	l = rand() % *a;
	//these are randomizing an int with the range of that specific array therefore the int won't try to call an element from an array that isn't there/ or wasn't created (that would be a seg fault ;)

	cout << "Most doctors agree that bicyle " << verbing_array[aa] << " is a/an " << adjective_array[b] << " form of exercise. " << verbing_array[c] << " a bicyle enables you to develop your " << noun_array[d] << " muscles, as well as increase the rate of your " << noun_array[e] << " beat. " << "More " << nouns_array[f] << " around the world " << verb_array[gg] << " bicyles than drive " << nouns_array[h] << ". No matter what kind of " << noun_array[i] << " you " << verb_array[j] << ", always be sure to wear a/an " << adjective_array[k] << " helmet. Make sure to have " << adjective_array[l] << " reflectors too!" << endl;

}

/***************************
 ** Function: story 2
 ** Description: randomizes integers with range depending on their specific word amount and prints the story with the random noun/verb/adjective
 ** Parameters: char *noun_array[]|*nouns_array[]|*verb_array[]|*verbing_array[]|*adjective_array[]|int *n|*s|*v|*g|*a
 ** Pre- Conditions: finish
 ** Post- Conditions: none
 ** Return: none
 **************************/
void story2(char *noun_array[], char *nouns_array[], char *verb_array[], char *verbing_array[], char *adjective_array[], int *n, int *s, int *v, int *g, int *a){

	int aa, b, c, d, e, f, gg, h, i, j, k, l, m, nn;
	srand(time(NULL));
	aa = rand() % *n;
	b = rand() % *a;
	c = rand() % *a;
	d = rand() % *n;
	e = rand() % *a;
	f = rand() % *n;
	gg = rand() % *a;
	h = rand() % *a;
	i = rand() % *v;
	j = rand() % *v;
	k = rand() % *n;
	l = rand() % *v;
	m = rand() % *a;
	nn = rand() % *v;

	cout << "Yesterday, " << noun_array[aa] << " and I went to the park. On our way to the " << adjective_array[b] << " park, we saw a " << adjective_array[c] << " " << noun_array[d] << " on a bike. We also saw big " << adjective_array[e] << " balloons tied to a " << noun_array[f] << ". Once we got to the " << adjective_array[gg] << " park, the sky turned " << adjective_array[h] << ". It started to " << verb_array[i] << " and " << verb_array[j] << ". " << noun_array[k] << " and I " << verb_array[l] << " all the way home. Tomorrow we will try to go to the " << adjective_array[m] << " park again and hope it doesn't " << verb_array[nn] << "." << endl;

}

/***************************
 ** Function: story 3
 ** Description: randomizes integers with range depending on their specific word amount and prints the story with the random noun/verb/adjective
 ** Parameters: char *noun_array[]|*nouns_array[]|*verb_array[]|*verbing_array[]|*adjective_array[]|int *n|*s|*v|*g|*a
 ** Pre- Conditions: finish
 ** Post- Conditions: none
 ** Return: none
 **************************/
void story3(char *noun_array[], char *nouns_array[], char *verb_array[], char *verbing_array[], char *adjective_array[], int *n, int *s, int *v, int *g, int *a){

	int aa, b, c, d, e, f, gg, h, i, j, k, l;
	srand(time(NULL));
	aa = rand() % *a;
	b = rand() % *n;
	c = rand() % *n;
	d = rand() % *a;
	e = rand() % *g;
	f = rand() % *n;
	gg = rand() % *n;
	h = rand() % *v;
	i = rand() % *n;
	j = rand() % *n;
	k = rand() % *v;
	l = rand() % *n;

	cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some " << adjective_array[aa] << " place to spend time with " << noun_array[b] << ". Getting to " << noun_array[c] << " is going to take " << adjective_array[d] << " hours. My favorite part of spring break is " << verbing_array[e] << " in the " << noun_array[f] << ". During spring break, " << noun_array[gg] << " and I plan to " << verb_array[h] << " all the way to " << noun_array[i] << ". After spring break, I will be ready to return to " << noun_array[j] << " and " << verb_array[k] << " hard to finish " << noun_array[l] << ". Thanks spring break 2017!" << endl;

}

int main(int argc, char *argv[]) {

	char word[75][40], *temp_noun[25], *noun_array[25], *nouns_array[25], *temp_verb[25], *verb_array[25], *verbing_array[25], *adjective_array[25];
	//temp arrays hold up to 25 nouns/verbs total, and this list could contain noun singular or plural/verb or verb-ing. 25 words for each category - noun/verb/adjective.
	int tn = 0, n = 0, s = 0, tv = 0, v = 0, g = 0, a = 0, length_noun = 0, length_verb = 0, check = atoi(argv[1]);
	//atoi changes the argv into an integer
	finish(word, temp_noun, noun_array, nouns_array, temp_verb, verb_array, verbing_array, adjective_array, &tn, &n, &s, &tv, &v, &g, &a, &length_noun, &length_verb);

	cout << noun_array[1] << endl;

	if (check > 3 || check < 1){ //if the user doesn't enter 1-3 in command line, tell them they're wrong and stop the program
		cout << "Error" << endl;
		return 0;
	}

	if (check == 1)
		story1(noun_array, nouns_array, verb_array, verbing_array, adjective_array, &n, &s, &v, &g, &a);

	if (check == 2)
		story2(noun_array, nouns_array, verb_array, verbing_array, adjective_array, &n, &s, &v, &g, &a);

	if (check == 3)
		story3(noun_array, nouns_array, verb_array, verbing_array, adjective_array, &n, &s, &v, &g, &a);

	return 0;
}
