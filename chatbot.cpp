#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT 100
void respond(char *input) 
{
    for (int i = 0; input[i]; i++) 
	{
        input[i] = tolower(input[i]);
    }
    if (strstr(input, "hello") != NULL || strstr(input, "hi") != NULL) 
	{
        printf("Chatbot: Hey there! ?? How's your day going?\n");
    } else if (strstr(input, "how are you") != NULL) 
	{
        printf("Chatbot: I'm doing well, thanks! Just here to chat with you. What’s up?\n");
    } else if (strstr(input, "what is your name") != NULL) 
	{
        printf("Chatbot: You can call me Chatbot, your friendly assistant! What's your name?\n");
    } else if (strstr(input, "bye") != NULL) 
	{
        printf("Chatbot: Aww, leaving already? ?? Take care and come back soon!\n");
    } else if (strstr(input, "what's the weather") != NULL || strstr(input, "how is the weather") != NULL) 
	{
        printf("Chatbot: I wish I could check the weather for you! But I hope it’s sunny and pleasant out there! ??\n");
    } else if (strstr(input, "tell me a joke") != NULL) 
	{
        printf("Chatbot: Alright, here’s one for you: Why did the bicycle fall over? Because it was two-tired! ??\n");
    } else if (strstr(input, "what can you do") != NULL) 
	{
        printf("Chatbot: I can chat, tell jokes, and answer questions. I’m here to make your day a bit brighter! What would you like to talk about?\n");
    } else if (strstr(input, "thank you") != NULL) 
	{
        printf("Chatbot: You're very welcome! ?? If you need anything else, just let me know!\n");
    } else 
	{
        printf("Chatbot: Hmm, I’m not quite sure how to respond to that. Can you tell me more?\n");
    }
}
int main() 
{
    char user[MAX_INPUT];
    printf("Welcome to the Chatbot! Type 'bye' to exit.\n");
    while (1) 
	{
        printf("You: ");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = 0;
        if (strcmp(user, "bye") == 0) 
		{
            respond(user);
            break;
        }
        respond(user);
    }
    return 0;
}

