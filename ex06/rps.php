<?php
echo "Choose rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN)));

while (!in_array($user_choice, array('rock', 'paper', 'scissors'))) {
    echo "Invalid choice.\nChoose rock, paper, or scissors: ";
    $user_choice = strtolower(trim(fgets(STDIN)));
}

$computer_choice = array('rock', 'paper', 'scissors')[rand(0,2)];

if ($user_choice === $computer_choice) {
    echo "Nobody won, equality!\n";
} else if (($user_choice === 'rock' && $computer_choice === 'scissors') ||
           ($user_choice === 'paper' && $computer_choice === 'rock') ||
           ($user_choice === 'scissors' && $computer_choice === 'paper')) {
    echo "Congratulations! You won! The computer chose $computer_choice.!\n";
} else {
    echo "Sorry, you lost. The computer chose $computer_choice.\n";
}
?>
