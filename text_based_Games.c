#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lucklessShot()
{
    int score = 0;
    int enemyLocation;
    int SuccessfullShot = 10,nearlySuccessfullShot = 5;
    int SuccessfullShotCounter = 0,nearlySuccessfullShotCounter = 0,UnsuccessfullShotCounter = 0;
    float locationEstimation;
    float mistakeRate,mistakeTotal=0;

    for (int i = 1; i <= 10; i++)
    {
        srand(time(NULL));
        enemyLocation = rand() % 10 + 1;
        printf("%d. enemy appeared.What location will you shot at ? : ",i);
        scanf("%f",&locationEstimation);

        if (locationEstimation > enemyLocation)
        {
            mistakeRate = locationEstimation - enemyLocation;
        }
        else
            mistakeRate = enemyLocation - locationEstimation;
        
        if (mistakeRate == 0)
        {
            score = score + 10;
            printf("You shoot successfully.You have gained 10 points!\n");
            SuccessfullShotCounter++;
        }
        else if (mistakeRate <= 0.5)
        {
            score = score + 5;
            printf("You missed the shot by a small margin.You have gained 5 points!\n");
            nearlySuccessfullShotCounter++;
        }
        else
        {
            printf("You missed the shot.\n");
            UnsuccessfullShotCounter++;
        }
        mistakeTotal = mistakeTotal + mistakeRate;
        printf("Enemy was in location %d\n",enemyLocation);
        printf("%d. shot' mistake rate: %f\n\n",i,mistakeRate);
    }
    printf("Total mistake rate in 10 shots : %f\n",mistakeTotal);
    printf("Total score in 10 shots : %d\n",score);
    printf("Successfull shots : %d\n",SuccessfullShotCounter);
    printf("Nearly successfull shots : %d\n",nearlySuccessfullShotCounter);
    printf("Unsuccessfull shots : %d\n",UnsuccessfullShotCounter);
    printf("Game Over!\n\n\n");
}

void numberle()
{
    int score = 100;
    int randomNum;
    int numberEstimation;
    int randomSayHundredsDigit,randomSayTensDigit,randomSayOnesDigit;
    int estimationHundredsDigit,estimationTensDigit,estimationOnesDigit;
    int hintHundredsDigit,hintTensDigit,hintOnesDigit;
    int estimationCounter=0;

    do
    {
        srand(time(NULL));
        randomNum = rand() % 900 + 100;
        randomSayHundredsDigit = randomNum / 100;
        randomSayTensDigit =  (randomNum / 10) % 10;
        randomSayOnesDigit = randomNum % 10;
    } while (randomSayHundredsDigit == randomSayTensDigit || randomSayHundredsDigit == randomSayOnesDigit || randomSayTensDigit == randomSayOnesDigit);

    
    printf("3 digit random number generated.\n");


    while (numberEstimation != randomNum && score > 0)
    {
        printf("%d.Write your estimation:\n",estimationCounter+1);
        scanf("%d",&numberEstimation);

        estimationHundredsDigit = numberEstimation / 100;
        estimationTensDigit = (numberEstimation / 10) % 10;
        estimationOnesDigit = numberEstimation % 10;

        if (estimationHundredsDigit == randomSayHundredsDigit)
        {
            hintHundredsDigit = 1;
        }
        else if (estimationHundredsDigit == estimationTensDigit || estimationHundredsDigit == randomSayHundredsDigit)
        {
            hintHundredsDigit = 9;
        }
        else   
            hintHundredsDigit = 0;

        if (estimationTensDigit == randomSayTensDigit)
        {
            hintTensDigit = 1;
        }
        else if (estimationTensDigit == randomSayHundredsDigit || estimationTensDigit == randomSayOnesDigit)
        {
            hintTensDigit = 9;
        }
        else   
            hintTensDigit = 0;

        if (estimationOnesDigit == randomSayOnesDigit)
        {
            hintOnesDigit = 1;
        }
        else if (estimationOnesDigit == randomSayTensDigit || estimationOnesDigit == randomSayHundredsDigit)
        {
            hintOnesDigit = 9;
        }
        else   
            hintOnesDigit = 0;
    
        if (numberEstimation != randomNum)
        {
            printf("Hint number:%d%d%d\n\n",hintHundredsDigit,hintTensDigit,hintOnesDigit);
            score = score - 10;
        }
        estimationCounter++;
    }
    if (score > 0)
        printf("Congratulations! You did guess correctly in %d. Your score : %d\n\n",estimationCounter,score);
    else 
        printf("Your score is over.Game Over!\n\n");
}

int main()
{
    int menuChoice;
    
    do
    {
        printf("Menu:\n");
        printf("[1].Luckless Shot\n");
        printf("[2].Numberle\n");
        printf("[3].About Games\n");
        printf("[4].Exit the menu\n");

        printf("Type the number ==> ");
        scanf("%d",&menuChoice);

        printf("\n");

        switch (menuChoice)
        {
        case 1:
            lucklessShot();
            break;

        case 2:
            numberle();
            break;
        case 3:
            printf("Luckless Shot:\nTrying to guess randomly appearing enemies location.You have '10' bullet.If you guess enemy's location correctly you will gain '10' points.Your guess - Enemy's location = Mistake rate.If u have '0.5' mistake rate or less you does nearly successfull shot and you will gain '5' points.If mistake rate much than '0.5' you does unsuccessfull shot and you haven't gain any point.\n\n");

            printf("Wordle:\nYou will try to guess '3' digit randomly generated number.After your guess,it will appear a hint number.If your guess has same digit with random number,that digit will be '1' in hint number.If your guess has same number but it stay on wrong digit,that digit will be '9' in hint number.If your guess hasn't same digit in random number,that digit will be '0' in hint number.\n\n");
            break;
        default:
            if (menuChoice != 4)
            {
                printf("Incorrect number!\n\n");
            }
            break;
        }
    } while (menuChoice != 4);
    
    printf("Program Out.");

    return 0;
}