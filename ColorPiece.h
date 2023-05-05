#pragma once

namespace model
{
	class ColorPiece
	{
	public:
		virtual ~ColorPiece() = default; // destructeur d'une classe de base doit �tre virtuel

		// TODO

	private:
		ColorPiece() = default; // peut pas �tre instanci�
		ColorPiece(const ColorPiece&) = delete; // pas de copie
		ColorPiece& operator=(const ColorPiece&) = delete; // pas d'affectation
	};
}