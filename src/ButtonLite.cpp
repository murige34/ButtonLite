/*
 * Copyright (c) 2019, Martin Urigelj All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY Martin Urigelj "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARDUINOGETSTARTED.COM BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ButtonLite.h>

Button::Button(uint8_t pin, uint8_t debounceTime) {
	_pin = pin;
	_debounceTime = debounceTime;
	
	_State = 0;
	_lastDebounceTime = 0;
}

void Button::begin(uint8_t mode) {
	pinMode(_pin, mode);
}

void Button::setDebounceTime(uint16_t time) {
	_debounceTime = min(time, 255);
}

uint8_t Button::getState(void) {
	return (_State & 0x01);
}

bool Button::isPressed(void) {
	return (_State & 0x03) == 0x01;
}

bool Button::isReleased(void) {
	return (_State & 0x03) == 0x02;
}

uint16_t Button::timePressed(void) {
	if( (_State & 0x01) ){
		return (millis() & 0xffff) - _lastDebounceTime;
	}else{
		return 0;
	}
}

void Button::loop(void) {
	uint8_t tmp;
	uint16_t currentTime = millis();

	if ( ( currentTime - _lastDebounceTime) >= _debounceTime) {
		// debounce time passed
		_State = (_State << 1) | !digitalRead(_pin);
		
		// save time at change
		if( (_State & 0x03) == 0x01 || (_State & 0x03) == 0x02){
			_lastDebounceTime = currentTime;
		}
		
		// prevent overflow of diference
		if( ( currentTime - _lastDebounceTime) >=  60000){
			_lastDebounceTime = currentTime - 60000;
		}
	}
	else{
		// we ignore change so we reproduce last  read
		tmp = _State & 0x01;
		_State = (_State<<1) | tmp;
	}
}

