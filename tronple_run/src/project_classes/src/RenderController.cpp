#include "project_classes/RenderController.hpp"


//**** CONTROLLER ****
RenderController::RenderController(SDLWindowManager* windowManager, ProgramList* programList)
: _windowManager(windowManager), _programList(programList){

	//Model
	Model coin("coin", "coin");
	Model bike("bike", "bike");
	Model cube("cube", "cube");
	Model skybox("skybox", "skybox");
	_model[0] = coin;
	_model[1] = bike;
	_model[2] = cube;
	_model[3] = skybox;
}

// **** MATRIX ****
//Getter
glm::mat4 RenderController::getProjMatrix() const{ 
	return _ProjMatrix;
}
glm::mat4 RenderController::getMVMatrix() const{ 
	return _MVMatrix;
}
glm::mat4 RenderController::getNormalMatrix() const{ 
	return _NormalMatrix;
}
glm::mat4 RenderController::getGlobalMVMatrix() const{ 
	return _GlobalMVMatrix;
}

//Setter
void RenderController::setProjMatrix(const glm::mat4 ProjMatrix){
	_ProjMatrix = ProjMatrix;
}

void RenderController::setMVMatrix(const glm::mat4 MVMatrix){
	_MVMatrix = MVMatrix;
}

void RenderController::setNormalMatrix(const glm::mat4 NormalMatrix){
	_NormalMatrix = NormalMatrix;
} 
void RenderController::setGlobalMVMatrix(const glm::mat4 GlobalMVMatrix){
	_GlobalMVMatrix = GlobalMVMatrix;
}


// **** PROGRAM ****
void RenderController::useProgram(const FS shader){
    switch (shader){
        case COIN :
            _programList->coinProgram->_program.use();
		break;
		case WORLD :
            _programList->worldProgram->_program.use();
		break;
		case TEXTURE :
            _programList->textureProgram->_program.use();
		break;
		case MULTILIGHT :
            _programList->multiLightProgram->_program.use();
		break;
	default : 
		break;
	}
}

// **** MODEL ****
Model RenderController::getModel(int i) const{
	return _model[i];
}

void RenderController::VModel(int i){
	_model[i].setVbo();
	_model[i].setIbo();
	_model[i].setVao();
}

void RenderController::bindModelVAO(int i){
	glBindVertexArray(_model[i].getVao());
}


glm::mat4 RenderController::useMatrixCoin(float x, float y, float z){
    glm::mat4 MVMatrix;

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(x, z, y)); 
    MVMatrix = glm::rotate(MVMatrix, _windowManager->getTime(), glm::vec3(0, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.4, 0.4, 0.4));  
    return MVMatrix;
}

glm::mat4 RenderController::useMatrixBike(float x, float y, float z, float orientation){
	glm::mat4 MVMatrix;
	MVMatrix = glm::translate(glm::mat4(1), glm::vec3(x, z - 0.35, y));
    MVMatrix = glm::rotate(MVMatrix, glm::radians(- float(orientation)), glm::vec3(0, 1, 0)); 
	return MVMatrix;
}

glm::mat4 RenderController::useMatrixCell(float x, float y, float z){
    glm::mat4 MVMatrix;
    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(x, z, y));
    return MVMatrix;
}

glm::mat4 RenderController::useMatrixSkybox(float x, float y, float z){
    glm::mat4 MVMatrix;
    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(x, z, y)); 
    MVMatrix = glm::rotate(MVMatrix, _windowManager->getTime()/10, glm::vec3(1, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.07, 0.07, 0.07));  
    return MVMatrix;
}

void RenderController::applyTransformations(FS shader, glm::mat4 MVMatrix){
    glm::mat4 lightMatrix;
    glm::vec4 lightVector;
    glm::mat4 _uProjection;

    switch (shader){
    	case COIN :
			glUniform1i(_programList->coinProgram->uTexture, 0);
    		glUniformMatrix4fv(_programList->coinProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix*MVMatrix));
    		glUniformMatrix4fv(_programList->coinProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    		glUniformMatrix4fv(_programList->coinProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
		break;
		case TEXTURE :
			glUniform1i(_programList->textureProgram->uTexture, 0);
			glUniformMatrix4fv(_programList->textureProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix));
			glUniformMatrix4fv(_programList->textureProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix));
			glUniformMatrix4fv(_programList->textureProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
			break;
		// case MULTILIGHT :
		// 	ambientLight = glm::vec3(.05);

		// 	for (std::vector<Light>::iterator it = _lights.begin(); it != _lights.end(); ++it) {
		// 		it->sendLightShader(_programList->multiLightProgram, refLight);
		// 	}

		// 	glUniform3f(glGetUniformLocation(_programList->multiLightProgram->_program.getGLId(), "uAmbientLight"), ambientLight.x, ambientLight.y, ambientLight.z);
		// 	glUniform1i(glGetUniformLocation(_programList->multiLightProgram->_program.getGLId(), "uNbLights"), _lightsCount);
		// 	glUniformMatrix4fv(_programList->multiLightProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix));
		// 	glUniformMatrix4fv(_programList->multiLightProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix));
		// 	glUniformMatrix4fv(_programList->multiLightProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
		// 	glUniform1i(_programList->multiLightProgram->uTexture, 0);
		// 	break;
		default : 
			break;
	}
}

void RenderController::drawModel(int i){
	glDrawElements(GL_TRIANGLES, _model[i].getGeometry().getIndexCount(), GL_UNSIGNED_INT, 0);
}

void RenderController::debindVAO(){
	glBindVertexArray(0);
}

RenderController::~RenderController(){
	_lights.clear();
	_lightsCount = 0;
}

void RenderController::enableCoinTexture(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _model[0].getTextureID());
}

/// \brief Activate and bind cube texture
void RenderController::enableCubeTexture(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model[2].getTextureID());
}

/// \brief Activate and bind bike texture
void RenderController::enableBikeTexture(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model[1].getTextureID());
}

void RenderController::disableTexture(){
    glBindTexture(GL_TEXTURE_2D, 0);
    glActiveTexture(GL_TEXTURE0);
}