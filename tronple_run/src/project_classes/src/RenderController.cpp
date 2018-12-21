#include "project_classes/RenderController.hpp"


//**** CONTROLLER ****
RenderController::RenderController(ProgramList* programList)
: _programList(programList){
 	
 	// A modifier
 	TrackballCamera camera;
  	camera.moveFront(-10.f);

	//Model
	Model coin("coin", "coin");
	Model bike("bike", "bike");
	_model[0] = coin;
	_model[1] = bike;

	//Matrix
	_GlobalMVMatrix = camera.getViewMatrix()*glm::translate(glm::mat4(1), glm::vec3(-3, -5, -5));
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
void RenderController::setProjMatrix(glm::mat4 ProjMatrix){
	_ProjMatrix = ProjMatrix;
}

void RenderController::setMVMatrix(glm::mat4 MVMatrix){
	_MVMatrix = MVMatrix;
}

void RenderController::setNormalMatrix(glm::mat4 NormalMatrix){
	_NormalMatrix = NormalMatrix;
}
void RenderController::setGlobalMVMatrix(glm::mat4 GlobalMVMatrix){
	_GlobalMVMatrix = GlobalMVMatrix;
}


// **** PROGRAM ****
void RenderController::useProgram(FS shader){
    switch (shader){
        case COIN :
            _programList->coinProgram->m_Program.use();
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


glm::mat4 RenderController::useMatrixCoin(){

    glm::mat4 MVMatrix;

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5)); 
    MVMatrix = glm::rotate(MVMatrix, (float)0 * glm::pi<float>()/180, glm::vec3(0, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(0.4, 0.4, 0.4)); 

    return MVMatrix;
}

glm::mat4 RenderController::useMatrixBike(){
	glm::mat4 MVMatrix;

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, 0)); 
    MVMatrix = glm::rotate(MVMatrix, (float)0 * glm::pi<float>()/180, glm::vec3(0, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(1, 1, 1)); 

    return MVMatrix;

}

glm::mat4 RenderController::useMatrixUp(){
    glm::mat4 MVMatrix;

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 7, 0)); 

    return MVMatrix;
}

glm::mat4 RenderController::useMatrixDown(){
	glm::mat4 MVMatrix;

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, -7, 0)); 

    return MVMatrix;
}



void RenderController::applyTransformations(FS shader, glm::mat4 MVMatrix){
    switch (shader){
    	case COIN :   
    		glUniformMatrix4fv(_programList->coinProgram->uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix*MVMatrix));
    		glUniformMatrix4fv(_programList->coinProgram->uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    		glUniformMatrix4fv(_programList->coinProgram->uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
		break;

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
}