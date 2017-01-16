# Creative Commons Attribution-ShareAlike 3.0 License -
# This work is licensed under the Creative Commons Attribution-Share Alike
# 3.0 License. To view a copy of this license,
# visit http://creativecommons.org/licenses/by-sa/3.0/legalcode;
# or, (b) send a letter to Creative Commons, 171 2nd Street, Suite 300, San
# Francisco, California, 94105, USA.
#
# Originally created : Mataru
#
JC=javac
JFLAGS=

# List of created class
CLASSES=		\
	google.class	\
	scada.class

classes: $(CLASSES:.java=.class)

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

# Defaults make targets
# Should be all??
defaults: classes

clean:
	$(RM) *.class
	$(RM) *~
	$(RM) *#*




