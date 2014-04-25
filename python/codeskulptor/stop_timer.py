#!/usr/bin/python
# CodeSkulptor,
#   url: http://www.codeskulptor.org/#user30_WcpCrJDbjD_2.py
#
# template for "Stopwatch: The Game"
import simplegui
import random

# define global variables
t = 0

# define helper function format that converts time
# in tenths of seconds into formatted string A:BC.D
def format(t):
    a = t / 6000
    b = (t % 6000) / 1000
    c = (t % 1000) / 100
    d = (t % 100) / 10
    e = t % 10
    return str(a) + ':' + str(b) + str(c) + '.' + str(d) + str(e)
    pass
    
# define event handlers for buttons; "Start", "Stop", "Reset"
def t_start():
    timer_1.start()
    pass

def t_stop():
    timer_1.stop()
    pass

def t_reset():
    global t
    t = 0
    pass

# define event handler for timer with 0.1 sec interval
def t_timer_handler_1():
    global t
    t += 1
#    print format(t)
    pass

# define draw handler
def draw(canvas):
    global t
    canvas.draw_text(format(t), [80, 110], 24, "white")

# create frame
frame = simplegui.create_frame("Converter", 200, 200)

# register event handlers
frame.set_draw_handler(draw)
frame.add_button("Start", t_start)
frame.add_button("Stop", t_stop)
frame.add_button("Reset", t_reset)

timer_1 = simplegui.create_timer(10, t_timer_handler_1)

# start frame

frame.start()

# Please remember to review the grading rubric

