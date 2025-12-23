#include <stdio.h>

int main(void) {
    int choice;

    printf("=== Baked Bakers Calc ===\n");
    printf("Choose a calculator:\n");
    printf("1) Hydration %% (water/flour * 100)\n");
    printf("2) Baker's %% + Total Dough (water%%, salt%%, total grams)\n");
    printf("3) Scale Recipe (keep ratios, change flour)\n");
    printf("4) Starter (preferment) + Overall Hydration\n");
    printf("Enter choice (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Input error: expected a number.\n");
        return 1;
    }

    switch (choice) {
    case 1: {
        int flour, water;
        double hydration;

        printf("\n[Hydration %%]\n");
        printf("Enter flour (g): ");
        if (scanf("%d", &flour) != 1) return 1;

        printf("Enter water (g): ");
        if (scanf("%d", &water) != 1) return 1;

        hydration = ((double)water / flour) * 100;

        printf("Hydration: %.1f%%\n", hydration);
        break;
    }

    case 2: {
        int flour, water, salt;
        int totalDough;
        double hydration, saltPercent;

        printf("\n[Baker's %% + Total Dough]\n");
        printf("Enter flour (g): ");
        if (scanf("%d", &flour) != 1) return 1;

        printf("Enter water (g): ");
        if (scanf("%d", &water) != 1) return 1;

        printf("Enter salt (g): ");
        if (scanf("%d", &salt) != 1) return 1;

        totalDough = flour + water + salt;
        hydration = ((double)water / flour) * 100;
        saltPercent = ((double)salt / flour) * 100;

        printf("Total dough: %d g\n", totalDough);
        printf("Hydration: %.1f%%\n", hydration);
        printf("Salt %%: %.1f%%\n", saltPercent);
        break;
    }

    case 3: {
        int flour, water, salt;
        int newFlour;
        double waterRatio, saltRatio;
        double newWater, newSalt, newTotal;

        printf("\n[Scale Recipe]\n");
        printf("Enter base flour (g): ");
        if (scanf("%d", &flour) != 1) return 1;

        printf("Enter base water (g): ");
        if (scanf("%d", &water) != 1) return 1;

        printf("Enter base salt (g): ");
        if (scanf("%d", &salt) != 1) return 1;

        printf("Enter new flour target (g): ");
        if (scanf("%d", &newFlour) != 1) return 1;

        /* Cast BEFORE division (critical) */
        waterRatio = (double)water / flour;
        saltRatio  = (double)salt  / flour;

        newWater = waterRatio * newFlour;
        newSalt  = saltRatio  * newFlour;
        newTotal = newFlour + newWater + newSalt;

        printf("Scaled water: %.1f g\n", newWater);
        printf("Scaled salt:  %.1f g\n", newSalt);
        printf("Scaled total dough: %.1f g\n", newTotal);
        break;
    }

    case 4: {
        int starterFlour, starterWater;
        int finalFlour, finalWater;
        int salt;

        int totalFlour, totalWater, totalDough;
        double starterHydration, overallHydration;

        printf("\n[Starter + Overall Hydration]\n");
        printf("Enter starter flour (g): ");
        if (scanf("%d", &starterFlour) != 1) return 1;

        printf("Enter starter water (g): ");
        if (scanf("%d", &starterWater) != 1) return 1;

        printf("Enter final flour (g): ");
        if (scanf("%d", &finalFlour) != 1) return 1;

        printf("Enter final water (g): ");
        if (scanf("%d", &finalWater) != 1) return 1;

        printf("Enter salt (g): ");
        if (scanf("%d", &salt) != 1) return 1;

        starterHydration = ((double)starterWater / starterFlour) * 100;

        totalFlour = starterFlour + finalFlour;
        totalWater = starterWater + finalWater;
        totalDough = totalFlour + totalWater + salt;

        overallHydration = ((double)totalWater / totalFlour) * 100;

        printf("Starter hydration: %.1f%%\n", starterHydration);
        printf("Total flour: %d g\n", totalFlour);
        printf("Total water: %d g\n", totalWater);
        printf("Overall hydration: %.1f%%\n", overallHydration);
        printf("Total dough: %d g\n", totalDough);
        break;
    }

    default:
        printf("Invalid choice. Please run again and pick 1-4.\n");
        break;
    }

    return 0;
}
