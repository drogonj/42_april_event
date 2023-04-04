#!/usr/bin/perl

print "Enter a string: ";
my $input = uc(<STDIN>);
# creation de la valeur input qui recupere STDIN avec uc() permettant de faire un toupper
chomp $input;
$input =~ s/[^A-Z]//g;
# permet de retirer le \n et les caracteres non alphabetiques

my $reversed_input = reverse $input;

if ($input eq $reversed_input) {
  print "The string is a palindrome!\n";
} else {
  print "The string is not a palindrome.\n";
}