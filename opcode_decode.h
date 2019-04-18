#ifndef OPCODE_DECODE_H
#define OPCODE_DECODE_H

// Automatically generated by generate_ops.py. DO NOT EDIT.

case SpvOpNop: {
    pgm->instructions.push_back(std::make_unique<InsnNop>());
    if(pgm->verbose) {
        std::cout << "Nop";
        std::cout << "\n";
    }
    break;
}

case SpvOpFunctionParameter: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFunctionParameter>(type, resultId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FunctionParameter";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << "\n";
    }
    break;
}

case SpvOpFunctionCall: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t functionId = nextu();
    std::vector<uint32_t> operandId = restv();
    pgm->instructions.push_back(std::make_unique<InsnFunctionCall>(type, resultId, functionId, operandId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FunctionCall";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " functionId ";
        std::cout << functionId;
        std::cout << " operandId ";
        for(int i = 0; i < operandId.size(); i++)
            std::cout << operandId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpLoad: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t pointerId = nextu();
    uint32_t memoryAccess = nextu(NO_MEMORY_ACCESS_SEMANTIC);
    pgm->instructions.push_back(std::make_unique<InsnLoad>(type, resultId, pointerId, memoryAccess));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "Load";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " pointerId ";
        std::cout << pointerId;
        std::cout << " memoryAccess ";
        std::cout << memoryAccess;
        std::cout << "\n";
    }
    break;
}

case SpvOpStore: {
    uint32_t pointerId = nextu();
    uint32_t objectId = nextu();
    uint32_t memoryAccess = nextu(NO_MEMORY_ACCESS_SEMANTIC);
    pgm->instructions.push_back(std::make_unique<InsnStore>(pointerId, objectId, memoryAccess));
    if(pgm->verbose) {
        std::cout << "Store";
        std::cout << " pointerId ";
        std::cout << pointerId;
        std::cout << " objectId ";
        std::cout << objectId;
        std::cout << " memoryAccess ";
        std::cout << memoryAccess;
        std::cout << "\n";
    }
    break;
}

case SpvOpAccessChain: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t baseId = nextu();
    std::vector<uint32_t> indexesId = restv();
    pgm->instructions.push_back(std::make_unique<InsnAccessChain>(type, resultId, baseId, indexesId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "AccessChain";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " baseId ";
        std::cout << baseId;
        std::cout << " indexesId ";
        for(int i = 0; i < indexesId.size(); i++)
            std::cout << indexesId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpVectorShuffle: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t vector1Id = nextu();
    uint32_t vector2Id = nextu();
    std::vector<uint32_t> componentsId = restv();
    pgm->instructions.push_back(std::make_unique<InsnVectorShuffle>(type, resultId, vector1Id, vector2Id, componentsId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "VectorShuffle";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " vector1Id ";
        std::cout << vector1Id;
        std::cout << " vector2Id ";
        std::cout << vector2Id;
        std::cout << " componentsId ";
        for(int i = 0; i < componentsId.size(); i++)
            std::cout << componentsId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpCompositeConstruct: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    std::vector<uint32_t> constituentsId = restv();
    pgm->instructions.push_back(std::make_unique<InsnCompositeConstruct>(type, resultId, constituentsId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "CompositeConstruct";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " constituentsId ";
        for(int i = 0; i < constituentsId.size(); i++)
            std::cout << constituentsId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpCompositeExtract: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t compositeId = nextu();
    std::vector<uint32_t> indexesId = restv();
    pgm->instructions.push_back(std::make_unique<InsnCompositeExtract>(type, resultId, compositeId, indexesId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "CompositeExtract";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " compositeId ";
        std::cout << compositeId;
        std::cout << " indexesId ";
        for(int i = 0; i < indexesId.size(); i++)
            std::cout << indexesId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpCompositeInsert: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t objectId = nextu();
    uint32_t compositeId = nextu();
    std::vector<uint32_t> indexesId = restv();
    pgm->instructions.push_back(std::make_unique<InsnCompositeInsert>(type, resultId, objectId, compositeId, indexesId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "CompositeInsert";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " objectId ";
        std::cout << objectId;
        std::cout << " compositeId ";
        std::cout << compositeId;
        std::cout << " indexesId ";
        for(int i = 0; i < indexesId.size(); i++)
            std::cout << indexesId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpImageSampleImplicitLod: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t sampledImageId = nextu();
    uint32_t coordinateId = nextu();
    uint32_t imageOperands = nextu();
    pgm->instructions.push_back(std::make_unique<InsnImageSampleImplicitLod>(type, resultId, sampledImageId, coordinateId, imageOperands));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "ImageSampleImplicitLod";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " sampledImageId ";
        std::cout << sampledImageId;
        std::cout << " coordinateId ";
        std::cout << coordinateId;
        std::cout << " imageOperands ";
        std::cout << imageOperands;
        std::cout << "\n";
    }
    break;
}

case SpvOpConvertFToS: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t floatValueId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnConvertFToS>(type, resultId, floatValueId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "ConvertFToS";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " floatValueId ";
        std::cout << floatValueId;
        std::cout << "\n";
    }
    break;
}

case SpvOpConvertSToF: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t signedValueId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnConvertSToF>(type, resultId, signedValueId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "ConvertSToF";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " signedValueId ";
        std::cout << signedValueId;
        std::cout << "\n";
    }
    break;
}

case SpvOpFNegate: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operandId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFNegate>(type, resultId, operandId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FNegate";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operandId ";
        std::cout << operandId;
        std::cout << "\n";
    }
    break;
}

case SpvOpIAdd: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnIAdd>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "IAdd";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFAdd: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFAdd>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FAdd";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFSub: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFSub>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FSub";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFMul: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFMul>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FMul";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpSDiv: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnSDiv>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "SDiv";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFDiv: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFDiv>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FDiv";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFMod: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFMod>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FMod";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpVectorTimesScalar: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t vectorId = nextu();
    uint32_t scalarId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnVectorTimesScalar>(type, resultId, vectorId, scalarId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "VectorTimesScalar";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " vectorId ";
        std::cout << vectorId;
        std::cout << " scalarId ";
        std::cout << scalarId;
        std::cout << "\n";
    }
    break;
}

case SpvOpVectorTimesMatrix: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t vectorId = nextu();
    uint32_t matrixId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnVectorTimesMatrix>(type, resultId, vectorId, matrixId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "VectorTimesMatrix";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " vectorId ";
        std::cout << vectorId;
        std::cout << " matrixId ";
        std::cout << matrixId;
        std::cout << "\n";
    }
    break;
}

case SpvOpMatrixTimesVector: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t matrixId = nextu();
    uint32_t vectorId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnMatrixTimesVector>(type, resultId, matrixId, vectorId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "MatrixTimesVector";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " matrixId ";
        std::cout << matrixId;
        std::cout << " vectorId ";
        std::cout << vectorId;
        std::cout << "\n";
    }
    break;
}

case SpvOpDot: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t vector1Id = nextu();
    uint32_t vector2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnDot>(type, resultId, vector1Id, vector2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "Dot";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " vector1Id ";
        std::cout << vector1Id;
        std::cout << " vector2Id ";
        std::cout << vector2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpLogicalOr: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnLogicalOr>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "LogicalOr";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpLogicalNot: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operandId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnLogicalNot>(type, resultId, operandId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "LogicalNot";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operandId ";
        std::cout << operandId;
        std::cout << "\n";
    }
    break;
}

case SpvOpSelect: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t conditionId = nextu();
    uint32_t object1Id = nextu();
    uint32_t object2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnSelect>(type, resultId, conditionId, object1Id, object2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "Select";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " conditionId ";
        std::cout << conditionId;
        std::cout << " object1Id ";
        std::cout << object1Id;
        std::cout << " object2Id ";
        std::cout << object2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpIEqual: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnIEqual>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "IEqual";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpSLessThan: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnSLessThan>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "SLessThan";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpSLessThanEqual: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnSLessThanEqual>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "SLessThanEqual";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFOrdEqual: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFOrdEqual>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FOrdEqual";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFOrdLessThan: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFOrdLessThan>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FOrdLessThan";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFOrdGreaterThan: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFOrdGreaterThan>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FOrdGreaterThan";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFOrdLessThanEqual: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFOrdLessThanEqual>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FOrdLessThanEqual";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpFOrdGreaterThanEqual: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t operand1Id = nextu();
    uint32_t operand2Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnFOrdGreaterThanEqual>(type, resultId, operand1Id, operand2Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "FOrdGreaterThanEqual";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operand1Id ";
        std::cout << operand1Id;
        std::cout << " operand2Id ";
        std::cout << operand2Id;
        std::cout << "\n";
    }
    break;
}

case SpvOpPhi: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    std::vector<uint32_t> operandId = restv();
    pgm->instructions.push_back(std::make_unique<InsnPhi>(type, resultId, operandId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "Phi";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " operandId ";
        for(int i = 0; i < operandId.size(); i++)
            std::cout << operandId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpBranch: {
    uint32_t targetLabelId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnBranch>(targetLabelId));
    if(pgm->verbose) {
        std::cout << "Branch";
        std::cout << " targetLabelId ";
        std::cout << targetLabelId;
        std::cout << "\n";
    }
    break;
}

case SpvOpBranchConditional: {
    uint32_t conditionId = nextu();
    uint32_t trueLabelId = nextu();
    uint32_t falseLabelId = nextu();
    std::vector<uint32_t> branchweightsId = restv();
    pgm->instructions.push_back(std::make_unique<InsnBranchConditional>(conditionId, trueLabelId, falseLabelId, branchweightsId));
    if(pgm->verbose) {
        std::cout << "BranchConditional";
        std::cout << " conditionId ";
        std::cout << conditionId;
        std::cout << " trueLabelId ";
        std::cout << trueLabelId;
        std::cout << " falseLabelId ";
        std::cout << falseLabelId;
        std::cout << " branchweightsId ";
        for(int i = 0; i < branchweightsId.size(); i++)
            std::cout << branchweightsId[i] << " ";
        std::cout << "\n";
    }
    break;
}

case SpvOpReturn: {
    pgm->instructions.push_back(std::make_unique<InsnReturn>());
    if(pgm->verbose) {
        std::cout << "Return";
        std::cout << "\n";
    }
    break;
}

case SpvOpReturnValue: {
    uint32_t valueId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnReturnValue>(valueId));
    if(pgm->verbose) {
        std::cout << "ReturnValue";
        std::cout << " valueId ";
        std::cout << valueId;
        std::cout << "\n";
    }
    break;
}

case SpvOpExtInst: {
    uint32_t type = nextu();
    uint32_t resultId = nextu();
    uint32_t ext = nextu();
    uint32_t opcode = nextu();
    if(ext == pgm->ExtInstGLSL_std_450_id) {
        switch(opcode) {
case GLSLstd450FAbs: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450FAbs>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450FAbs";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Floor: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Floor>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Floor";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Fract: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Fract>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Fract";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Radians: {
    uint32_t degreesId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Radians>(type, resultId, degreesId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Radians";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " degreesId ";
        std::cout << degreesId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Sin: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Sin>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Sin";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Cos: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Cos>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Cos";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Atan: {
    uint32_t y_over_xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Atan>(type, resultId, y_over_xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Atan";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " y_over_xId ";
        std::cout << y_over_xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Atan2: {
    uint32_t yId = nextu();
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Atan2>(type, resultId, yId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Atan2";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Pow: {
    uint32_t xId = nextu();
    uint32_t yId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Pow>(type, resultId, xId, yId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Pow";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Exp: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Exp>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Exp";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Exp2: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Exp2>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Exp2";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450FMin: {
    uint32_t xId = nextu();
    uint32_t yId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450FMin>(type, resultId, xId, yId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450FMin";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450FMax: {
    uint32_t xId = nextu();
    uint32_t yId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450FMax>(type, resultId, xId, yId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450FMax";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450FClamp: {
    uint32_t xId = nextu();
    uint32_t minValId = nextu();
    uint32_t maxValId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450FClamp>(type, resultId, xId, minValId, maxValId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450FClamp";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " minValId ";
        std::cout << minValId;
        std::cout << " maxValId ";
        std::cout << maxValId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450FMix: {
    uint32_t xId = nextu();
    uint32_t yId = nextu();
    uint32_t aId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450FMix>(type, resultId, xId, yId, aId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450FMix";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << " aId ";
        std::cout << aId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Step: {
    uint32_t edgeId = nextu();
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Step>(type, resultId, edgeId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Step";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " edgeId ";
        std::cout << edgeId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450SmoothStep: {
    uint32_t edge0Id = nextu();
    uint32_t edge1Id = nextu();
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450SmoothStep>(type, resultId, edge0Id, edge1Id, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450SmoothStep";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " edge0Id ";
        std::cout << edge0Id;
        std::cout << " edge1Id ";
        std::cout << edge1Id;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Length: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Length>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Length";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Distance: {
    uint32_t p0Id = nextu();
    uint32_t p1Id = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Distance>(type, resultId, p0Id, p1Id));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Distance";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " p0Id ";
        std::cout << p0Id;
        std::cout << " p1Id ";
        std::cout << p1Id;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Cross: {
    uint32_t xId = nextu();
    uint32_t yId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Cross>(type, resultId, xId, yId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Cross";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << " yId ";
        std::cout << yId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Normalize: {
    uint32_t xId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Normalize>(type, resultId, xId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Normalize";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " xId ";
        std::cout << xId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Reflect: {
    uint32_t iId = nextu();
    uint32_t nId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Reflect>(type, resultId, iId, nId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Reflect";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " iId ";
        std::cout << iId;
        std::cout << " nId ";
        std::cout << nId;
        std::cout << "\n";
    }
    break;
}

case GLSLstd450Refract: {
    uint32_t iId = nextu();
    uint32_t nId = nextu();
    uint32_t etaId = nextu();
    pgm->instructions.push_back(std::make_unique<InsnGLSLstd450Refract>(type, resultId, iId, nId, etaId));
    pgm->resultTypes[resultId] = type;
    if(pgm->verbose) {
        std::cout << "GLSLstd450Refract";
        std::cout << " type ";
        std::cout << type;
        std::cout << " resultId ";
        std::cout << resultId;
        std::cout << " iId ";
        std::cout << iId;
        std::cout << " nId ";
        std::cout << nId;
        std::cout << " etaId ";
        std::cout << etaId;
        std::cout << "\n";
    }
    break;
}

            default: {
                if(pgm->throwOnUnimplemented) {
                    throw std::runtime_error("unimplemented GLSLstd450 opcode " + GLSLstd450OpcodeToString[opcode] + " (" + std::to_string(opcode) + ")");
                } else {
                    std::cout << "unimplemented GLSLstd450 opcode " << GLSLstd450OpcodeToString[opcode] << " (" << opcode << ")\n";
                    pgm->hasUnimplemented = true;
                }
                break;
            }
        }
    } else {
        throw std::runtime_error("unimplemented instruction " + std::to_string(opcode) + " from extension set " + std::to_string(ext));
    }
    break;
}

#endif // OPCODE_DECODE_H
