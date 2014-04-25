#!/usr/bin/python
# CodeSkulptor,
#   url: http://www.codeskulptor.org/#user30_dCwafdOb9n_7.py
#
# template for "Guess the number" mini-project
# input will come from buttons and an input field
# all output for the game will be printed in the console

import simplegui
import random
import math

# initialize global variables used in your code
target_number = 0
guess_number = 0
guess_count = 0
guess_done = 0
guess_hint = 0

# helper function to start and restart the game
def new_game():
    global guess_count, inp, guess_done, guess_hint
    global guess_number
    guess_hint = 0
    guess_count = 0
    guess_done = 0
    guess_number = 0
    inp.set_text('')
    print "new game"

# define event handlers for control panel
def range100():
    # button that changes range to range [0,100) and restarts
    global target_number
    target_number = random.randint(0, 100)
    # print target_number
    # remove this when you add your code    
    pass

def range1000():
    # button that changes range to range [0,1000) and restarts
    global target_number
    target_number = random.randint(0, 1000)
    
    # remove this when you add your code    
    pass
    
def input_guess(guess):
    global target_number, guess_count, guess_number
    global guess_done, guess_hint
    # main game logic goes here 
    guess_count+=1
    guess_number = int(guess)
    if(int(guess) == target_number):
        guess_done = 1
        guess_hint = 0
        print "Bingo!", target_number, "is correct!"
    elif (int(guess) > target_number):
        print "Lower"
        guess_hint = -1
        
    else:
        print "Higher"
        guess_hint = 1
    print "Guess count:", guess_count
    # remove this when you add your code
    pass

# define draw handler
def draw(canvas):
    global guess_number, guess_done
    if guess_done == 0:
        canvas.draw_text(str(guess_number),[150-22, 100+22], 44, "Grey")
    else:
        canvas.draw_text(str(guess_number),[150-22, 100+22], 44, "Yellow")
    if guess_hint < 0:
        canvas.draw_text("Lower",[150-5*24/2/2, 100+22+24], 24, "Lightgreen")
#        canvas.draw_circle([110, 140], 2, 2, "Yellow")
    elif guess_hint > 0:
        canvas.draw_text("Higher",[150-6*24/2/2, 100-24], 24, "Red")
#        canvas.draw_circle([110, 60], 2, 2, "Yellow")
        
#    canvas.draw_circle([100, 100], 12, 2, "Red")
    
# create frame
frame = simplegui.create_frame("DJ's Guess Number", 300, 200)

# register event handlers for control elements
frame.add_button("Random 0..100", range100)
frame.add_button("Random 0..1000", range1000)
inp = frame.add_input("Guess", input_guess, 100)
frame.set_draw_handler(draw)



# call new_game and start frame
frame.add_button("New Game", new_game)
frame.start()


# always remember to check your completed program against the grading rubric

