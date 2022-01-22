# Development

To clone the repo:

```
https://github.com/cdv-group-c/restaurant.git
```

If you want to use SSH keys follow this tutorial: https://docs.github.com/en/authentication/connecting-to-github-with-ssh
and then you can use:

```
git@github.com:cdv-group-c/restaurant.git
```

We recommend using Visual Studio 2022 as an IDE.
We work in the simplified version of Git flow. To start working on a new feature or bug fix:

- create a branch from the `main` branch
- remember to commit your changes regularly
- create a pull request on Github
- after review, merge the branch to the `main` branch

# App structure

The app structure is based on 4 main modules:

- delivery
- menu
- summary
- state

The full flowchart is available here: https://www.figma.com/file/2G16RzL1u4UfopfYBH0OeU/Restaurant?node-id=0%3A1

## Delivery

The first part of the app.
The main goal of this module is to collect data about user delivery preferences.
To calculate the fastest possible delivery time it uses current time to validate user input and determine the closest delivery time (minimum waiting time is 1h).

## Menu

This part is responsible for displaying the restaurant's menu and redirecting user to the next steps.
The user is choosing the meal and the quantity of it and at this point, he can choose options like:

- add another meal
- remove meal
- go to summary
- exit the app

To add or remove meal the app uses the `state` module.

## Summary

The summary displays all of the collected data and asks the user to save the order to the file.

## State

This module reads information from the entry file and extracts data to the app.
We use `|` separated values in the entry file to split the data.
It has two state variables:

- `orderedMeals`: the list of ordered meal's ids;
- `mealIds` - the vector of ids of all the meals.

You can access this state in whole application by getters functions: `getOrderedMeals` and `getMealIds`.
