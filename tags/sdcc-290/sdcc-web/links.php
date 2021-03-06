﻿<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
  <meta content="text/html; charset=UTF-8" http-equiv="content-type" />
  <title>SDCC links page</title>
  <link type="text/css" href="style.css" rel="stylesheet" />
  <link rel="shortcut icon" type="image/x-icon" href="/images/sdcc.ico" />
</head>
<body link="teal" vlink="#483d8b">
<div align="left">
<h1>SDCC - Links and More!</h1>
<table bgcolor="white" border="0" cellpadding="2" cellspacing="1" width="100%">
  <tbody>
    <tr>
      <td valign="top" width="15%"><?php echo(file_get_contents('./left_menu.inc'));?><br />
      </td>
      <td width="85%">
      <h2>Links - General</h2>
      <p>
      <a href="http://www.webring.org/cgi-bin/webring?ring=80x51;list">
The 8051 Web Ring</a>
<img src="images/x51chip.jpg" alt="webring icon" align="middle" height="63" width="81" /><br />
      <a href="http://www.willem.org/">PcGenerator</a>
EpromProgrammer,Pic24C and more...<br />
      <a href="http://www.needhams.com">Needham Electronics</a>
- various device programmers, all sizes, all prices<a href="http://www.sensorella.da.ru"><br />
Sensorella</a>
- Dual 8051 board, ADCs and <i>lots</i> of I/O.<br />
      <a href="http://www.systronix.com">Systronix</a>
- Makers of the STEP and STEP+ for the DallasTINI board (a must see for embedded
ethernet and Dallas 390's)<br />
      <a href="http://www.microcontroller.com">Microcontroller.com</a>
- Micros and Embedded stuff. Not to be confused with
microcontrollers.com (Arrow Electronics... what a joke!)<br />
      <a href="http://www.aesmicro.com/8051.htm">AES Micro</a>
- nice but a bit expensive, may be just what some one needs though.<br />
      <a href="mailto:karl@turbobit.com">Karl
Bongers</a> has a start on a <a href="http://www.turbobit.com/sdcc.html">Summary/FAQ</a>
about SDCC. (*highly* recommended reading!)<br />
      <a href="http://www.rabbitsemiconductor.com">Rabbit
Semiconductor</a> - Z-World based boards, very small and lots of
I/O. Kits available.<br />
      <a href="http://www.flexgate.de">FlexGate</a>
- '552 based boards with onboard ethernet. (German, not much on the web
site yet)<br />
      <a href="http://mikrokontrolery.of.pl/">mikrokontrolery.of.pl</a>
- wszystko o mikrokontrolerach jednoukładowych 8051 AVR PIC<br />
      <a href="http://www.bhargavaz.net/main.html">www.bhargavaz.net</a>
-<br />
      <a href="http://www.dcd.pl/">Digital Core Design</a>&nbsp;-
private Intellectual Property (IP) Core provider and System-on-Chip
(SoC) design house<br />
      <a href="http://microcontrollershop.com/">MicroController
Pros
Corporation (&micro;CPros)</a> - Development Tools for All
Major Microcontroller Architectures<br />
      <a href="http://www.soudez.be/">www.soudez.be</a>
-&nbsp;<span class="genmed"><font face="Arial, sans-serif"><span style="text-decoration: none;">DS89C450</span></font></span>
system over USB port in a standard DIL40 package<br />
      <a href="http://www.proware.ind.br">www.proware.ind.br</a>
-&nbsp;<span class="genmed"><font face="Arial, sans-serif"><span style="text-decoration: none;">8051</span></font></span>
development board with SDCC library code<br />
      </p>
      <h2>Links - Code Sources</h2>
      <p>
      <a href="http://www.programmersheaven.com/zone5/cat27/index.htm">Programmers
Heaven</a> - 8051 resources, sample code and compilers<br />
      <a href="http://www.pjrc.com/tech/8051/index.html">Paul
Stoffregen's Home Page</a> - Home of PAULMON and other code
snippets.<br />
      <a href="http://www.8052.com">8052.COM</a>
- resources, sample code.<br />
      <a href="http://www.freertos.org/">FreeRTOS</a>
- a portable, open source, mini Real Time Kernel<br />
      </p>
      <h2>Links - Circuit Boards and EDA software</h2>
      <p>
      <a href="http://www.geocities.com/pdmtr">PC
board HOWTO using Press &amp; Peel Tech Film</a><br />
      <a href="http://www.cadsoft.de">CadSoft</a> -
makers of
Eagle EDA software, download a free (somewhat restricted) version for
Win32 or Linux.<br />
      </p>
      <h2>Links - IC Data and Searches</h2>
      <p>
      <a href="http://www.datasheetlocator.com">DataSheetLocator</a>
- This is just the most fabulous web site I have been to in a long
time. Need info? Go here!<br />
      </p>
      <h2>Links - Embedded Ethernet</h2>
      <p>
      <a href="mailto:werner.cornelius@gmx.de">Werner
Cornelius</a>
has a <a href="http://www.titro.de/ethernet/">web page</a>
devoted to embedding the RealTek RTL8019AS ethernet controller chip
into a microcontroller. Lots of small tips on wiring, what to do, and
what not to do.<br />
      </p>
      <h2>Links - LCD Stuff</h2>
      <p>
      <b>T6963 controlled LCD panels </b>(includes
the Optrex DM-5000 series and others) </p>
      <p> A couple of pictures of an lcd panel with a familiar phrase.<br />
      <a href="lcd/MVC-003X.JPG">LCD picture 1 - full view</a>
Feb 15,2000 10:54:02 PM (133K jpg) <br />
      <a href="lcd/MVC-006X.JPG">LCD picture 2 - close up</a>
Feb 15,2000 10:57:06 PM (139K jpg)<br />
      <a href="lcd/lcdsource.tar.gz">source</a>
written by <a href="mailto:dave@kd0yu.com">Dave Helton</a>,
(compile with sdcc) (44K tar.gz format)<br />
      </p>
      <p>Note:<br />
There are no docs for the source...
yet ;-) This is alpha-ware at best. It works in my system. Through the
winter of 2000-01 I will be updating the code and writing some docs.
This may force me to write better code if I have to document it. Your
feedbeed back on the code is welcome. If you have enhanced the code,
made a better mouse trap... please email me and let me know.<br />
      </p>
      <h2>Links - simulators</h2>
      <p>
      <a href="http://www.dattalo.com/gnupic/gpsim.html">gpsim</a>
- gpsim is a full-featured software simulator for Microchip PIC
microcontrollers distributed under the GNU General Public License<br />
      <a href="http://mazsola.iit.uni-miskolc.hu/%7Edrdani/embedded/ucsim/">&micro;Csim</a>
- the old ucsim page<br />
      </p>
      <hr />
      <p><i>If you have a link to an embedded
application, either hardware or software, that you believe would be of
interest to other readers, drop either myself or the list members a
note.</i></p>
      <p><a href="http://sourceforge.net/tracker/?func=add&amp;group_id=599&amp;atid=536150">Send
us your link!</a></p>
<?php include('./footer.php')?>
      </td>
    </tr>
  </tbody>
</table>
</div>
</body>
</html>
