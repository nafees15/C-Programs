/********* Programming Assignment 3 *******************/
/************* Group project **************************/
/******************** Main file ***********************/
/************ Net ID : Nafees Noor -> nn319918 ********/
/************ Net ID: Jake Ruth -> JR236759 ***********/
/************** Nafees Noor & Jake Ruth ***************/
/************* Discussion 1.40 pm - 2.35 pm ***********/
/******************************************************/

#include <stdio.h>  // Libaries
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*******  All the Magic Numbers Declarations ***** */
#define SIZE 4
#define TRUE 1
#define FALSE 0
/* ****** All the Magic Numbers Declarations ****** */

struct node
{
  int coefficient;
  int exponent;
  struct node *pNext;
};

/******* Function prototypes **************/

void addCoefficient(struct node **start, int coef, int ex);
void printList(struct node *start);
void deleteExponent(struct node ** ,int );
void printLargest(struct node **);
void printSmallest(struct node **);
void printCoefficient(struct node ** , int );
void printDegree(struct node **start);
void deleteInRange(struct node **start, int ex1, int ex2);
void value(struct node *start, int value);

/*********** Funtion protopes *************/


int main(void)
{
  /* All the variables used for taking input from the user and calling the functions */
  int c, e, e2, val;
  int deleteExp;
  int showExp;
  
  char command[SIZE];  //Array to store the commands from the user
  
  /*initialize linked to null*/
  struct node *head=NULL;
  
  printf("\nPlease choose the  commands below\n");
  printf("\n************** Polynomial's program commands *******************\n");
  printf("**   adc -> To add Coefficient                                **\n");
  printf("**   dex -> To delete Exponent                                **\n");
  printf("**   der -> To delete Exponent range command                  **\n");
  printf("**   prp -> To print the current polynomial                   **\n");
  printf("**   prd -> To print the degree                               **\n");
  printf("**   pvp -> To print the value of polynomial                  **\n");
  printf("**   prd -> To print the degrees of the polynomial            **\n");
  printf("**   prc -> Print Coefficient of the polynomial               **\n");
  printf("**   plc -> Print the largest coefficient of the polynomial   ** \n");
  printf("**   psc -> Print the smallest coefficient of the polynomial  **\n");
  printf("**   end -> To end this program                               **\n");
  printf("************** Polynomials' program commands *******************\n\n");
  
  fflush(stdout);
  printf("Please enter a command: ");
  fflush(stdout);
  scanf("%s",command);   // taking input command from the user
  
  while(strcmp(command,"end")!=0)
    {
      if(strcmp(command,"adc")==0)   // For the adc command, taking coefficient and exponent from the user
	{ 
	  printf("Enter a coefficient and an exponent: ");
	  fflush(stdout);
	  scanf("%d%d",&c,&e);
	  addCoefficient(&head,c,e); // calling the addcoefficient funtion
	}
      
      if(strcmp(command, "dex") == 0) // For the dex command
	{
	  printf("Please enter the exponent: \n");
	  fflush(stdout);
	  scanf("%d", &deleteExp);
	  deleteExponent(&head, deleteExp); // Calling the dex command with head of the list and the expoent they want to delete
	}
      if(strcmp(command, "prc") == 0)	   // For the prc command
	{
	  printf("enter the exponent\n");
	  scanf("%d", &showExp);
	  printCoefficient(&head, showExp); // Calling the printCoefficient method with head of the list and exponent they want to find
	}
      
      if(strcmp(command, "plc") == 0)	// For the plc command
	{
	  printLargest(&head);		// Calling the printLargest function with head of the list
	  
	}
      
      if(strcmp(command, "psc") == 0) // For the psc command
	{
	  printSmallest(&head);  // Calling the printSmallest function with head of the list
	}
      
      if(strcmp(command, "pvp")==0)  // For the pvp command
	{
	  printf("Enter a value: \n");
	  fflush(stdout);
	  scanf("%d", &val);
	  value(head, val);	// Calling the value function with head and value they wish to compute
	}
      
      if(strcmp(command, "prd")==0)  //For the prd command
	{
	  printDegree(&head);		// Calling the printDegree function with head of the list as parameter
	}
      
      if(strcmp(command, "der")==0)  // For the der command
	{
	  printf("Enter two exponent values: \n");
	  fflush(stdout);
	  scanf("%d%d",&e, &e2);
	  deleteInRange(&head, e, e2); // calling the deleteInRange function with head, e and e2 values from the user as parameter
	}
      
      if(strcmp(command,"prp")==0)  // For the prp command
	{
	  printList(head); //Calling the printList function with head of the list as parameter
	}
      fflush(stdout);
      printf("Please enter a command: ");
      fflush(stdout);
      scanf("%s",command);
      
      
      
    } // End of the while loop to take command from the user
  return 0;
  
}

/********************************* All the functions below *************************/


/****************** ADC (Add Coefficient Funtion)**********************/
/***  This function take three parameters *****************************/
/***  @ **start as the head of the list *******************************/
/***  @ coef variable as coeffient provided by the user ****************/
/***  @ ex command as exponent by the user ****************************/
/*** This function add the coefficient in the list in order ***********/
/*** It sorts out the biggest exponent in front and lowest ************/
/*** in the back, it also add the coefficient if the exponent *********/
/*** if the same exponent already there in the list ********************/
/***********************************************************************/
void addCoefficient(struct node **start, int coef, int ex)
{
  struct node *temp, *storeStart; // local node is being created to go through the list and maintain the list
  storeStart=(*start);	// making the storeStart to point the head node of the list
  

  /* special case if there are no nodes in the list and creating the list for first time */  
  if(*start==NULL)
    {
      /* checks to ensure space is allocated for the new node */
      if((temp=(struct node*)malloc(sizeof(struct node)))==NULL) //Creating the node using malloc
	{
	  printf("Allocation failed.\n");
	  fflush(stdout);
	  exit(1);
	}
      temp->coefficient=coef;
      temp->exponent=ex;
      temp->pNext=NULL;
      (*start)=temp;
      return;
    }/* end special case */
  
  /* allocate space for temp */
  if((temp=(struct node*)malloc(sizeof(struct node)))==NULL)
    {
      printf("Allocation failed.\n");
      fflush(stdout);
      exit(1);
    }
  /* special case if there is only one object in the list */
  if((*start)->pNext==NULL)
    {
      if(ex==(*start)->exponent)
	{
	  (*start)->coefficient+=coef;
	  return;
	}
      if(ex>(*start)->exponent)	      // If the exponent given by the user is bigger than which already
	{                             // in the list then creating creating a node and make it as head node   
	  temp->coefficient=coef;     // and the first node become the second node in the list
	  temp->exponent=ex;       
	  temp->pNext=(*start);
	  *start=temp;
	  return;
	}
      else
	{
	  temp->coefficient=coef;     // else adding the node behind the existed node in the list
	  temp->exponent=ex;
	  temp->pNext=NULL;
	  (*start)->pNext=temp;
	  return;
	}
    }/* end special case */

  /* for when there are 2 or more object in list */
  /* check to see if exponent already exists in the list */

  while((*start)->pNext!=NULL)
    {
      /* if the exponent at the beginning of the list is  equal to ex, add the coefficients */
      if((*start)->exponent==ex){
	(*start)->coefficient+=coef; /* if the exponent value already exists, add coefficients */
	(*start)=storeStart;
	return;
      }

      /* if the proceeding exponent is equal, add coefficients */
      if((*start)->pNext->exponent==ex)
	{
	  (*start)->pNext->coefficient+=coef;
	  (*start)=storeStart;
	  return;
	}
      
      /* if the inputted exponent value is greater then current node's exponent value
	 then since the list is ordered from highest exponent to lowest, the
	 value cannot already exist in the list, therefore add a node to the
	 list at this point */

      if((*start)->exponent<ex)
	{
	  temp->coefficient=coef;
	  temp->exponent=ex;
	  temp->pNext=(*start);
	  *start=temp;
	  return;
	}
      if (((*start)->pNext->exponent)<ex)
	{
	  temp->coefficient=coef;
	  temp->exponent=ex;
	  temp->pNext=(*start)->pNext;
	  (*start)->pNext=temp;
	  (*start)=storeStart;
	  return;
	}
      /*special case: when there are two elements in the list, and the new polynomial is
	to be added to the end of the list*/
      
      if((((*start)->pNext->exponent)>ex)&&((*start)->pNext->pNext==NULL))
	{
	  temp->exponent=ex;
	  temp->coefficient=coef;
	  temp->pNext=NULL;
	  (*start)->pNext->pNext=temp;
	  (*start)=storeStart;
	  return;
	}
      /*checks to see if the polynomial should be added to the end of the list
	if yes, then a special case exists*/
      
      /* special case: new polynomial to be added to the end of the list */
      if((((*start)->pNext->pNext->exponent)>ex)&&((*start)->pNext->pNext==NULL))
	{
	  temp->exponent=ex;
	  temp->coefficient=coef;
	  temp->pNext=NULL;
	  (*start)->pNext->pNext=temp;
	  return;
	}
      /*special case: exponents needs to be added to the end of the list */
      if(((*start)->pNext->pNext->exponent)==ex)
	{
	  (*start)->pNext->pNext->coefficient+=coef;
	  (*start)=storeStart;
	  return;
	}
      /* end speciale cases */
      *start=(*start)->pNext;

    } /*end while */
  
  /* if this point is reached, then the polynomial was not added to the list and therefor
      should be added to the end of the list */
  
  start=(&storeStart);
}

/************************* printList Funtion *************************/
/*** This function *start as a parameter which represent as the head */
/*** of the list then this function prints the current polynomial ****/
/*********************************************************************/
void printList(struct node *start)
{
  struct node *storeStart=start; // local pointer node and initilize to star
                                 // or the first node in the list

  /*delete any terms with a coeffeicient equal to 0*/
  while((start)!=NULL)
    {
      if((*start).coefficient==0)
	{
	  deleteExponent((&storeStart),(*start).exponent);
	}
      start=(*start).pNext;
    }
  start=(storeStart);
  /* if the list s empty print out a preset value */
  if (start==NULL)
    {
      printf("0x^0");
    }
  /*base case*/
  else
    {
      while(start!=NULL)
	{
	  if(start->coefficient>0){printf("+"); }
	  printf("%dx^%d ",start->coefficient,start->exponent);  // printing out the current polynomial funtion
	  fflush(stdout);
	  start=start->pNext;
	}
    }
  /* print a newline */
  printf("\n");
  fflush(stdout);
} /* end printList */


/******************** Delete Exponent Funtion *********************/
/*** This function takes three parameters *************************/
/*** **start as head node of the list, then integer deleteExp *****/
/*** which is the value given by the user. Then this function *****/
/*** checks if the value of deleteExp exit in the list or not *** */
/*** If it exist then it will delete it ***************************/
/******************************************************************/
void deleteExponent(struct node **start, int deleteExp)
{
  struct node *temp;
  
  temp = *start;    // setting temp as head node
  
  if((temp) == NULL)
    {
      return ;
    }

  if((temp -> pNext == NULL) && (temp ->exponent == deleteExp))  //Special case: if you are trying to delete the only item in the list
    {
      free(*start);
      *start = NULL;
      return ;
    }
  
  if((temp -> exponent) == deleteExp)  // Special case: If you trying to delete the head  node in the list
    {
      *temp =  *temp -> pNext;
    }
  

  while((temp) -> pNext != NULL)    // Base case for all other node
    {
      
      if((temp) -> pNext -> exponent  == deleteExp)
	{
	  if(temp -> pNext -> pNext == NULL)    // Checking if the node one next is equal to null then set the next node to Null so the last node will be deleted
	    {
	      temp -> pNext  = NULL;     //Special case: if i am trying to delete the last node in the list
	      return ;
	    }
	  
	  (temp) -> pNext = (temp) ->pNext -> pNext;   // Deleting the node which contains the user given exponent
	}
      
      temp = temp -> pNext;   // looping through the loop
      
    }

  return ;

}

/******************* PLC (Print largest coefficient command ******************/
/*** This functions takes just one parameter named **start which is the head */
/*** of the list. This function goes through the list and print out the *****/
/*** largest coefficient is on the current polynomial funtion ***************/
/****************************************************************************/
void printLargest(struct node **start)
{
  int largest = 0;      // local variable to keep track of the largest coefficient in the list
  struct node *temp;   // local node to go through the list
  temp = *start;

  if(temp == NULL) // Special Case: if there's no node in the list
    {
      printf("%d\n", largest);
      return ;
    }

  largest = (temp) -> coefficient;  //Initilizing the largest variable with the first coefficient in the list

  if((temp) -> pNext == NULL)  //Special Case: If there's only one item in the list
    {
      largest = (temp) -> coefficient;
      printf("The largest coeffiecient in the list is %d\n", largest);
      return ;
    }
  
  while((temp) != NULL)         //General case for all other case it will loop and will look for the largest coefficient
    {
      if((temp) -> coefficient > largest)
	{
	  largest = (temp) -> coefficient;
	}
      temp = (temp) -> pNext;
    }
  
  printf("The largest coeffiecient in the list is %d\n", largest);  // Finally printing out the largest coefficient in the list
  
  return ;
  
}


/*********************** PSC (Print smaller coefficient funtion ************************/
/*** This function takes just one parameter **start as a head node of the list *********/
/*** Then this function go through the list and finds the smallest coefficient *********/
/***************************************************************************************/
void printSmallest(struct node **start)
{
  int smallest = 0;   // Local variable to keep track of the smallest coefficient in the list
  struct node *temp;  // local temp node to go through the list
  temp = *start;     // making temp to first node in the list
  
  if(temp == NULL)   // Special Case: If there's no item in the list
    {
      printf("%d\n", smallest) ;
      return ;
    }
  
  smallest = temp -> coefficient;

  if(temp -> pNext == NULL)   // Special Case: If there's only one item in the list
    {
      smallest = temp -> coefficient;
      printf("The smallest coeffiecient in the list is %d\n", smallest);
      return ;
    }

  while(temp != NULL)   // For general case
    {
      if( temp -> coefficient < smallest)
	{
	  smallest = temp -> coefficient;  // Looping through and finding the smallest coefficient in the list
	}
      temp = temp -> pNext;
    }
  

  printf("The smallest coefficient in the list is %d\n", smallest); // Finally printing the smallest coefficient in the list
  
  return ;
}

/******************** PRC (Print Coefficient) ******************************/
/*** This function takes two parameters **start as head of the list ********/
/*** and integer showExp to print the coefficient that matches with the ****/
/*** given value in showExp from the user. If anything does not match then */
/*** It simply just prints 0 to the user ***********************************/
/***************************************************************************/
void printCoefficient(struct node **start, int showExp)
{
  struct node *temp;
  temp = *start;     // local node to go through the list
  
  if(temp == NULL)
    {
      return ;
    }
  
  while(temp != NULL)
    {
      if(temp -> exponent == showExp) // looping through the list and printout if it matchwith showExp value
	{
	  printf("%d\n", temp -> coefficient);
	  return ;
	}
      
      temp = temp -> pNext;
    }
  printf("0\n");   // If none of them are match in the list that means that value is not in the list so it just simply print 0

  return ;
}


/********************** PRD (Print Degree Funtion) *****************************/
/*** This functions takes one parameter in the list named **start as head ******/
/*** node in the list then it prints out the degree of the polynomial **********/
/*******************************************************************************/
void printDegree(struct node **start)
{
  if(*start==NULL)
    {
      printf("0\n");
      return;
    } //if the list is emptey return 0

  printf("%d\n",(*start)->exponent);
}


/********************* DER (Delete Exponent Range Funtion) *************************/
/*** This function takes three parameter **start as head node then integer ex1,ex2 */
/*** Then this function deletes a range of polynomials whos exponent falls *********/ 
/*** in the range of ex1<=exponent<=ex2 ********************************************/
/***********************************************************************************/
void deleteInRange(struct node **start, int ex1, int ex2)
{
  int i; //counter variable
  for(i=ex1; i<=ex2; i++)
    {
      deleteExponent(start, i); //call to deleteExponent function
    }
} /*end deleteInRange function */



/********************* PVP (Print Value Of the Polynomial Function) ********************/
/**** This function takes two parameter **start as head parameter and integer value ****/
/**** this is the value is given by the user then it plugs for all the x inside the ****/
/**** function and after plug in for all the x it solves it and prints the number ******/
/***************************************************************************************/ 
void value(struct node *start, int value)
{
  int sum=0;
  int coef, ex, i;
  int x=value;
  
  /* evaluates the function at the value */
  while((start)!=NULL){
    ex=(*start).exponent;
    coef=(*start).coefficient;
    /* computes value to the power of ex */
    
    for(i=0;i<ex-1;i++){
      x=x*value;
    }
    if(ex==0){x=1;}
    sum+=(x*coef);
    start=(*start).pNext;
    x=value;
  }
  printf("The value is: %d\n", sum);
  return;
}

/************************************ End OF The File **************************************/
/*******************************************************************************************/
