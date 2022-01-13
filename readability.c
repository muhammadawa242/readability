#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main()
{
	string text = get_string("Text: ");
	int L = count_letters(text);
	int W = count_words(text);
	int S = count_sentences(text);
	float l = ((float)L/W)*100;
	float s = ((float)S/W)*100;
	float index = 0.0588 * l - 0.296 * s - 15.8;
	if (index < 1)
	{
		printf("Below Grade 1\n");
	}
	else if (index >= 16)
	{
		printf("Grade 16+\n");
	}
	else
	{
	index = round(index);
	printf("Grade %i\n",(int)index);
	}
}

int count_letters(string text)
{
	int letters = 0;
	int i;
	for (i = 0; i < strlen(text); i++)
	{
		if (isalpha(text[i]))
		{
			letters++;
		}
	}
	return letters;
}

int count_words(string text)
{
	int i;
	int words = 0;
	for (i = 0; i < strlen(text); i++)
	{
		if (isspace(text[i]))
		{
			words++;
		}
	}
	words = words + 1;
	return words;
}

int count_sentences(string text)
{
    int i;
	int sentences = 0;
	for (i = 0; i < strlen(text); i++)
	{
		if (text[i]==46||text[i]==33||text[i]==63)
		{
			sentences++;
		}
	}
	return sentences;
}
