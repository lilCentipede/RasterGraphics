/*PPM pb(3, 2, "letshope", 255);
	std::ifstream in("ColorText.txt");
	pb.readPixels(in);
	pb.printPixels();
	pb.rotate("left");
	pb.printPixels();
	pb.grayscale();
	pb.printPixels();*/

	/*history.addChange("grayscale");
history.getLastChange()->printPixels();
history.addChange("rotateleft");
history.getLastChange()->printPixels();
history.addChange("monochrome");
history.getLastChange()->printPixels();
history.addChange("undo");
history.getLastChange()->printPixels(); */

//Image* i;
	//i = new PPM(1, 1, "first", 255);
	//i->readPixels();
	////ImageHistory history("first", i);
	////i = nullptr;
	//Session session(1,i);
	//session.addChange("grayscale");
	//session.getImageByName("first").getLastChange()->printPixels();
	//session.addChange("monochrome");
	//session.getImageByName("first").getLastChange()->printPixels();
	//session.undo();
	//session.getImageByName("first").getLastChange()->printPixels();


//std::ifstream in;
//in.open("testPBM.txt");
//Image* i;
//i = new PBM(4, 3, "first", 1);
//i->readPixels(in);
//Session s(1, i);
//s.addChange("grayscale");
//s.sessioninfo();
//std::cout << "-------------------------------------------------------\n";
//in.close();
//
//in.open("testPGM.txt");
//i = new PGM(4, 3, "second", 16);
//i->readPixels(in);
//s.addImage(i);
//s.addChange("monochrome");
//s.sessioninfo();
//std::cout << "-------------------------------------------------------\n";
//in.close();
//
//in.open("testPPM.txt");
//i = new PGM(2, 2, "third", 255);
//i->readPixels(in);
//s.addImage(i);
//s.addChange("rotateleft");
//s.sessioninfo();
//std::cout << "-------------------------------------------------------\n";
//s.undo();
//s.sessioninfo();