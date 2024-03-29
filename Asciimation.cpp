﻿///Trevor Adams, taadams1@dmacc.edu, 2-24-19
//implementation of asciimation class
//added/updated functions for integration into "Sketch Artist" project

#include "Asciimation.h"

//default speed set on construction
Asciimation::Asciimation() {
	this->speed = 8;
}

//deconstructor
Asciimation::~Asciimation()
{
}

//method to set animation speed, later converted to milliseconds
//between 1 and 5 frames per second (bigger number = slower)
void Asciimation::SetSpeed(float spd) {

	// numbers between 0.5 and 10 allowed (20fps-1fps)
		if (spd >= 0.5 && spd <= 10) {
			this->speed = spd;
		}
		else {
			std::wcout << L"Speed must be a number from 0.5 - 10." << std::endl;
		}
}

//show current animation speed
void Asciimation::ShowSpeed() {
	
	std::wstring output;
	int spd = this->speed;
	//calculate frames per second
	float fps = (float)10 / (this->speed);

	std::wcout << L"Speed: " << std::to_wstring(spd) << std::endl;
	std::wprintf(L"Frames per second: %4.2f",fps);//print fps with 2 decimals
	std::wcout << std::endl;

	//added delay while testing to debug speed output
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

//return current speed setting
float Asciimation::GetSpeed() {
	return this->speed;
}

//set frames for flower animation
//each frame is a vector of wstring
void Asciimation::Flower() {
	this->frames = {
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|   ,   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|   ,   |)",
	 LR"(|   ⌠   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|   ,   |)",
	 LR"(|   ⌡   |)",
	 LR"(|   ⌠   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|   Ω   |)",
	 LR"(|   ⌡   |)",
	 LR"(|   ⌠   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|  \Ω/  |)",
	 LR"(|   ┼   |)",
	 LR"(|   ⌡   |)",
	 LR"(|   ⌠   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|  ≥Ǚ≤  |)",
	 LR"(|  »┼«  |)",
	 LR"(|   ⌡   |)",
	 LR"(|   ⌠   |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|   \σ  |)",
	 LR"(|   /‾` |)",
	 LR"(| » ⌡   |)",
	 LR"(|   ⌠ « |)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|   /‾`α|)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|    _,˳|)",
	 LR"(‾‾‾‾‾‾‾‾‾)" },
	{ LR"(_________)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|       |)",
	 LR"(|    ̲ ̫|)",
	 LR"(‾‾‾‾‾‾‾‾‾)" }
	};
}

//method to animate based on frames selected
void Asciimation::Animate() {

	if ((this->frames).empty()) {
		std::wcout << L"Animation not selected" << std::endl;
	}
	else {

		//force output to unicode
		_setmode(_fileno(stdout), _O_U16TEXT);

		//convert speed to milliseconds
		int speed = 100 * GetSpeed();

		//loop through and output each frame
		for (int i = 0; i < frames.size(); i++) {
			//clear screen to prepare for animation
			system("CLS");
			for (int j = 0; j < (frames[i]).size(); j++) {
				std::wcout << frames[i][j] << std::endl;
			}
			//pause for time based on speed input
			std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		}
		//clear screen at end of animation
		system("CLS");
	}
}

//overload of animate to allow repeating of animation
void Asciimation::Animate(int repeat) {

	if ((this->frames).empty()) {
		std::wcout << L"Animation not selected" << std::endl;
	}
	else {
		//force output to unicode
		_setmode(_fileno(stdout), _O_U16TEXT);

		//convert speed to milliseconds
		int speed = 100 * GetSpeed();

		//loop for number of repititions
		for (int r = 0; r < repeat; r++) {
			//loop through and output each frame
			for (int i = 0; i < frames.size(); i++) {
				//clear screen to prepare for animation
				system("CLS");
				for (int j = 0; j < (frames[i]).size(); j++) {
					std::wcout << frames[i][j] << std::endl;
				}
				//pause for time based on speed input
				std::this_thread::sleep_for(std::chrono::milliseconds(speed));

			}
		}
	}
}

void Asciimation::RevealFace() {
	this->speed = 0.7;
	this->frames = {
		{LR"(-------------------------)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒|)",
		LR"(|▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░|)",
		LR"(|▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒|)",
		LR"(|▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒|)",
		LR"(|░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░|)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░|)",
		LR"(|░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░|)",
		LR"(|▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒|)",
		LR"(|▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒|)",
		LR"(|░▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒░|)",
		LR"(|░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░|)",
		LR"(-------------------------)"},

		{ LR"(-------------------------)",
		LR"(|░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░|)",
		LR"(|░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒|)",
		LR"(|░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░|)",
		LR"(|░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░|)",
		LR"(|░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░|)",
		LR"(-------------------------)" },

		{LR"(-------------------------)",
		LR"(| ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░ |)",
		LR"(|░░▒▒▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒▒░░░|)",
		LR"(|░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░|)",
		LR"(|░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░|)",
		LR"(|░░░▒▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒▒░░░|)",
		LR"(| ░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░ |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|  ░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░  |)",
		LR"(| ░░░▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒░░░ |)",
		LR"(|░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░|)",
		LR"(|░░▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒░░|)",
		LR"(| ░░░▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒░░░ |)",
		LR"(|  ░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░  |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|   ░░░░▒▒▒▒▒▒▒▒▒░░░░   |)",
		LR"(| ░░░▒▒▒▒▓▓▓▓▓▓▓▒▒▒▒░░░ |)",
		LR"(|░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░|)",
		LR"(|░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░|)",
		LR"(| ░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░ |)",
		LR"(|  ░░░▒▒▒▓▓▓▓▓▓▓▒▒▒░░░  |)",
		LR"(|    ░░░▒▒▒▒▒▒▒▒▒░░░    |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|     ░░░░░░░░░░░░░     |)",
		LR"(|   ░░▒▒▒▒▒▒▒▒▒▒▒▒▒░░   |)",
		LR"(| ░░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒▒░░ |)",
		LR"(| ░▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒░ |)",
		LR"(|░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░|)",
		LR"(|░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░|)",
		LR"(| ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░ |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|   ░░░▒▒▓▓▓▓▓▓▓▒▒░░░   |)",
		LR"(|     ░░▒▒▒▒▒▒▒▒▒░░     |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|      ░░░░░░░░░░░      |)",
		LR"(|    ░░░▒▒▒▒▒▒▒▒▒░░░    |)",
		LR"(|  ░░▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒░░  |)",
		LR"(|  ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░  |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░ |)",
		LR"(| ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░ |)",
		LR"(| ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░ |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░ |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|    ░░▒▒▓▓▓▓▓▓▓▒▒░░    |)",
		LR"(|      ░░▒▒▒▒▒▒▒░░      |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(|     ░░▒▒▒▒▒▒▒▒▒░░     |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|  ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░  |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░ |)",
		LR"(| ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░ |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|     ░░▒▓▓▓▓▓▓▓▒░░     |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|      ░░▒▒▒▒▒▒▒░░      |)",
		LR"(|    ░░▒▒▓▓▓▓▓▓▓▒▒░░    |)",
		LR"(|   ░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░   |)",
		LR"(|  ░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░  |)",
		LR"(|  ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░  |)",
		LR"(|  ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░  |)",
		LR"(|  ░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒░  |)",
		LR"(|  ░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░  |)",
		LR"(|   ░░▒▓▓▓▓▓▓▓▓▓▓▓▒░░   |)",
		LR"(|    ░░▒▓▓▓▓▓▓▓▓▓▒░░    |)",
		LR"(|     ░░▒▓▓▓▓▓▓▓▒░░     |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(|     ░░░▒▒▒▒▒▒▒░░░     |)",
		LR"(|   ░░░▒▒▓▓▓▓▓▓▓▒▒░░░   |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|  ░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░  |)",
		LR"(|  ░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░  |)",
		LR"(|  ░░▒▓▓▓▓▓▓▓▓▓▓▓▓▓▒░░  |)",
		LR"(|  ░░░▒▓▓▓▓▓▓▓▓▓▓▓▒░░░  |)",
		LR"(|   ░░░▒▓▓▓▓▓▓▓▓▓▒░░░   |)",
		LR"(|    ░░░▒▓▓▓▓▓▓▓▒░░░    |)",
		LR"(|      ░░▒▒▓▓▓▒▒░░      |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|        ░░░░░░░        |)",
		LR"(|      ░░▒▒▒▒▒▒▒░░      |)",
		LR"(|    ░░▒▒▒▓▓▓▓▓▒▒▒░░    |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|    ░░▒▒▓▓▓▓▓▓▓▒▒░░    |)",
		LR"(|     ░░▒▒▓▓▓▓▓▒▒░░     |)",
		LR"(|      ░░░▒▒▒▒▒░░░      |)",
		LR"(|        ░░░░░░░        |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(|     ░░░▒▒▒▒▒▒▒░░░     |)",
		LR"(|    ░░▒▒▒▓▓▓▓▓▒▒▒░░    |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|  ░░▒▒▓▓▓▓▓▓▓▓▓▓▓▒▒░░  |)",
		LR"(|   ░░▒▒▓▓▓▓▓▓▓▓▓▒▒░░   |)",
		LR"(|    ░░▒▒▓▓▓▓▓▓▓▒▒░░    |)",
		LR"(|     ░░▒▒▒▓▓▓▒▒▒░░     |)",
		LR"(|      ░░░▒▒▒▒▒░░░      |)",
		LR"(|        ░░░░░░░        |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(|      ░░▒▒▒▒▒▒▒░░      |)",
		LR"(|     ░▒▒▒▒▓▓▓▒▒▒▒░     |)",
		LR"(|    ░▒▒▒▓▓▓▓▓▓▓▒▒▒░    |)",
		LR"(|   ░▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒░   |)",
		LR"(|   ░▒▒▒▓▓▓▓▓▓▓▓▓▒▒▒░   |)",
		LR"(|    ░▒▒▒▓▓▓▓▓▓▓▒▒▒░    |)",
		LR"(|     ░▒▒▒▓▓▓▓▓▒▒▒░     |)",
		LR"(|      ░░▒▒▒▒▒▒▒░░      |)",
		LR"(|       ░░░░░░░░░       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|         ░░░░░         |)",
		LR"(|       ░░░▒▒▒░░░       |)",
		LR"(|      ░▒▒▒▒▒▒▒▒▒░      |)",
		LR"(|     ░▒▒▒▓▓▓▓▓▒▒▒░     |)",
		LR"(|    ░▒▒▒▓▓▓▓▓▓▓▒▒▒░    |)",
		LR"(|    ░▒▒▒▓▓▓▓▓▓▓▒▒▒░    |)",
		LR"(|     ░▒▒▒▓▓▓▓▓▒▒▒░     |)",
		LR"(|      ░▒▒▒▓▓▓▒▒▒░      |)",
		LR"(|       ░░▒▒▒▒▒░░       |)",
		LR"(|        ░░░░░░░        |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|        ░░░░░░░        |)",
		LR"(|       ░▒▒▒▒▒▒▒░       |)",
		LR"(|      ░▒▒▓▓▓▓▓▒▒░      |)",
		LR"(|     ░▒▒▓▓▓▓▓▓▓▒▒░     |)",
		LR"(|     ░▒▒▓▓▓▓▓▓▓▒▒░     |)",
		LR"(|      ░▒▒▓▓▓▓▓▒▒░      |)",
		LR"(|       ░▒▒▒▒▒▒▒░       |)",
		LR"(|        ░░░░░░░        |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|         ░░░░░         |)",
		LR"(|        ░▒▒▒▒▒░        |)",
		LR"(|       ░▒▒▓▓▓▒▒░       |)",
		LR"(|       ░▒▒▓▓▓▒▒░       |)",
		LR"(|        ░▒▒▒▒▒░        |)",
		LR"(|         ░░░░░         |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|          ░░░          |)",
		LR"(|         ░░▒░░         |)",
		LR"(|        ░▒▓▓▓▒░        |)",
		LR"(|        ░▒▓▓▓▒░        |)",
		LR"(|         ░░▒░░         |)",
		LR"(|          ░░░          |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|          ░░░          |)",
		LR"(|         ░▒▓▒░         |)",
		LR"(|         ░▒▓▒░         |)",
		LR"(|          ░░░          |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|           ░           |)",
		LR"(|          ░▒░          |)",
		LR"(|          ░▒░          |)",
		LR"(|           ░           |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|           ░           |)",
		LR"(|           ░           |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"},

		{LR"(-------------------------)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(|                       |)",
		LR"(-------------------------)"} };

}
